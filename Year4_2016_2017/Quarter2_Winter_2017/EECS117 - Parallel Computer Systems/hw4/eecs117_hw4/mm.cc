#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "timer.c"

#define N_ 4096
#define K_ 4096
#define M_ 4096
#define B_ 2 //added default blocksize value

typedef double dtype;

void verify(dtype *C, dtype *C_ans, int N, int M)
{
  int i, cnt;
  cnt = 0;
  for(i = 0; i < N * M; i++) {
    if(abs (C[i] - C_ans[i]) > 1e-6) cnt++;
  }
  if(cnt != 0) printf("ERROR\n"); else printf("SUCCESS\n");
}

void mm_serial (dtype *C, dtype *A, dtype *B, int N, int K, int M)
{
  int i, j, k;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      for(int k = 0; k < K; k++) {
        C[i * M + j] += A[i * K + k] * B[k * M + j];
      }
    }
  }
}

void mm_cb (dtype *C, dtype *A, dtype *B, int N, int K, int M, int blocksize)
{
  /* =======================================================+ */
  /* Implement your own cache-blocked matrix-matrix multiply  */
  /* =======================================================+ */
	
	int imax, jmax, kmax;
	dtype t0;

	//Traverse outer blocks
	for (int i0 = 0; i0 < N; i0 += blocksize) {
		imax = i0 + blocksize > N ? N : i0 + blocksize;

		for (int j0 = 0; j0 < M; j0 += blocksize) {
			jmax = j0 + blocksize > M ? M : j0 + blocksize;

			for (int k0 = 0; k0 < K; k0 += blocksize) {
				kmax = k0 + blocksize > K ? K : k0 + blocksize;

				//Traverse inner blocks
				for (int i1 = i0; i1 < imax; i1++) {
					for (int j1 = j0; j1 < jmax; j1++) {
						t0 = C[i1 * M + j1];
						for (int k1 = k0; k1 < kmax; k1++) {
							t0 += A[i1 * K + k1] * B[k1 * M + j1];
						}
						C[i1 * M + j1] = t0;
					}
				}
			}
		}
	}
}

void mm_sv (dtype *C, dtype *A, dtype *B, int N, int K, int M, int blocksize)
{
  /* =======================================================+ */
  /* Implement your own SIMD-vectorized matrix-matrix multiply  */
  /* =======================================================+ */

	int imax, jmax, kmax;
	dtype t0, t1, t2, t3;

	//Traverse outer blocks
	for (int i0 = 0; i0 < N; i0 += blocksize) {
		imax = i0 + blocksize > N ? N : i0 + blocksize;

		for (int j0 = 0; j0 < M; j0 += blocksize) {
			jmax = j0 + blocksize > M ? M : j0 + blocksize;

			for (int k0 = 0; k0 < K; k0 += blocksize) {
				kmax = k0 + blocksize > K ? K : k0 + blocksize;

				//Traverse inner blocks
				for (int i1 = i0; i1 < imax; i1++) {
					for (int j1 = j0; j1 < jmax; j1+=4) {
						t0 = C[i1 * M + j1];
						t1 = C[i1 * M + (j1 + 1)];
						t2 = C[i1 * M + (j1 + 2)];
						t3 = C[i1 * M + (j1 + 3)];
						for (int k1 = k0; k1 < kmax; k1++) {
							t0 += A[i1 * K + k1] * B[k1 * M + j1];
							t1 += A[i1 * K + k1] * B[k1 * M + (j1 + 1)];
							t2 += A[i1 * K + k1] * B[k1 * M + (j1 + 2)];
							t3 += A[i1 * K + k1] * B[k1 * M + (j1 + 3)];
						}
						C[i1 * M + j1] = t0;
						C[i1 * M + (j1 + 1)] = t1;
						C[i1 * M + (j1 + 2)] = t2;
						C[i1 * M + (j1 + 3)] = t3;
					}
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
  int i, j, k;
  int N, K, M;
  int blocksize;//added blocksize variable

  //added blocksize as a command line arguement
  if(argc == 5) {
    N = atoi (argv[1]);		
    K = atoi (argv[2]);		
    M = atoi (argv[3]);		
	blocksize = atoi(argv[4]);
    printf("N: %d K: %d M: %d blocksize: %d\n", N, K, M, blocksize);
  } else {
    N = N_;
    K = K_;
    M = M_;
	blocksize = B_;
	printf("N: %d K: %d M: %d blocksize: %d\n", N, K, M, blocksize);
  }

  dtype *A = (dtype*) malloc (N * K * sizeof (dtype));
  dtype *B = (dtype*) malloc (K * M * sizeof (dtype));
  dtype *C = (dtype*) malloc (N * M * sizeof (dtype));
  dtype *C_cb = (dtype*) malloc (N * M * sizeof (dtype));
  dtype *C_sv = (dtype*) malloc (N * M * sizeof (dtype));
  assert (A && B && C);

  /* initialize A, B, C */
  srand48 (time (NULL));
  for(i = 0; i < N; i++) {
    for(j = 0; j < K; j++) {
      A[i * K + j] = drand48 ();
    }
  }
  for(i = 0; i < K; i++) {
    for(j = 0; j < M; j++) {
      B[i * M + j] = drand48 ();
    }
  }
  bzero(C, N * M * sizeof (dtype));
  bzero(C_cb, N * M * sizeof (dtype));
  bzero(C_sv, N * M * sizeof (dtype));

  stopwatch_init ();
  struct stopwatch_t* timer = stopwatch_create ();
  assert (timer);
  long double t;

  printf("Naive matrix multiply\n");
  stopwatch_start (timer);
  /* do C += A * B */
  mm_serial (C, A, B, N, K, M);
  t = stopwatch_stop (timer);
  printf("Done\n");
  printf("time for naive implementation: %Lg seconds\n\n", t);


  printf("Cache-blocked matrix multiply\n");
  stopwatch_start (timer);
  /* do C += A * B */
  mm_cb (C_cb, A, B, N, K, M, blocksize); //modified mm_cb with blocksize function parameter
  t = stopwatch_stop (timer);
  printf("Done\n");
  printf("time for cache-blocked implementation: %Lg seconds\n", t);

  /* verify answer */
  verify (C_cb, C, N, M);

  printf("SIMD-vectorized Cache-blocked matrix multiply\n");
  stopwatch_start (timer);
  /* do C += A * B */
  mm_sv (C_sv, A, B, N, K, M, blocksize); //modified mm_sv with blocksize function parameter
  t = stopwatch_stop (timer);
  printf("Done\n");
  printf("time for SIMD-vectorized cache-blocked implementation: %Lg seconds\n", t);

  /* verify answer */
  verify (C_sv, C, N, M);

  return 0;
}
