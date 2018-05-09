/**
*  \file parallel-mergesort.cc
*
*  \brief Implement your parallel mergesort in this file.
*
*	Jack Melcher
*	67574625
*	2/4/2017
*	EECS 117
*	Hw1 Part1
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <omp.h>

#include "sort.hh"

void mergesort(keytype* A, int p, int r);
void merge(keytype* A, int p, int q, int r);


void parallelSort(int N, keytype* A) {
	/* Lucky you, you get to start from scratch */
	int i = 0;

	omp_set_num_threads(1);
	/*
	for (i = 0; i < N; i++) {
	printf("A[%d] = %d\n", i, A[i]);
	}
	*/
	#pragma omp parallel
	#pragma omp single nowait
	mergesort(A, 0, N-1);

	/*
	for (i = 0; i < N; i++)
		printf("A[%d] = %d\n", i, A[i]);
	*/
}

//Parallel merge sort
void mergesort(keytype* A, int p, int r) {
	int q = 0;

	if (p < r) {
		q = (p + r) / 2;
		#pragma omp task
		mergesort(A, p, q);
		mergesort(A, q + 1, r);
		#pragma omp taskwait

		merge(A, p, q, r);
	}
}

//Serial merge
void merge(keytype* A, int p, int q, int r) {
	int i = 0, j = 0, k = 0;

	int n1 = q - p + 1;
	int n2 = r - q;

	keytype* L = newKeys(n1);
	keytype* R = newKeys(n2);

	for (i = 0; i < n1; i++) {
		L[i] = A[p + i];
		//printf("L[%d] = %d\n", i, L[i]);
	}
	for (j = 0; j < n2; j++) {
		R[j] = A[q + j + 1];
		//printf("R[%d] = %d\n", j, R[j]);
	}

	i = 0;
	j = 0;

	//printf("p = %d, q = %d, r = %d\n", p, q, r);

	for (k = p; k <= r; k++) {
		//printf("k = %d, i = %d, j = %d\n", k, i, j);
		
		//Insert right if left has already been completed
		if (i == n1) {
			A[k] = R[j];
			j++;
		}
		//Insert left if right has already been completed
		else if (j == n2) {
			A[k] = L[i];
			i++;
		}
		//Insert left if it's less than or equal to right
		else if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		//Insert right if it's less than left
		else if (L[i] > R[j]) {
			A[k] = R[j];
			j++;
		}		
	}

	free(L);
	free(R);
}



/* eof */
