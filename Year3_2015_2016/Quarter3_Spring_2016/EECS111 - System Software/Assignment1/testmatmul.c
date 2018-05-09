#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void GenRandomInput(int* target, int size);
void Print2DMatrix(int* target, int size);

int main(int argc, char* argv[]) {

	// capture the input argument
	int matrix_size = 0; //all matrices will be square aka.N x N
	
	if (argc == 2) {
		matrix_size = atoi(argv[1]);
	}
	else { matrix_size = 4; }

	srand(time(NULL));

	int* A = NULL;
	int* B = NULL;

	int* C = NULL;
	int sum, i, j, e;



	A = (int*)malloc(matrix_size*matrix_size*sizeof(int)); //allocate 2D array that is a 1D bucket
	B = (int*)malloc(matrix_size*matrix_size*sizeof(int)); //allocate 2D array that is a 1D bucket

	GenRandomInput(A, matrix_size);
	GenRandomInput(B, matrix_size);



	C = (int*)malloc(matrix_size*matrix_size*sizeof(int));

	//Matrix Multiplication
	for (i = 0; i<matrix_size; i++) {
		for (j = 0; j<matrix_size; j++) {
			sum = 0;
			for (e = 0; e<matrix_size; e++) {
				sum += A[i*matrix_size + e] * B[e*matrix_size + j];
			}
			C[i*matrix_size + j] = sum;
		}
	}

	// Print result from parent
	printf("\nInput matrix1: \n");
	Print2DMatrix(A, matrix_size);

	printf("Input matrix2: \n");
	Print2DMatrix(B, matrix_size);

	printf("Output matrix: \n");
	Print2DMatrix(C, matrix_size);

	free(A);
	free(B);
	free(C);

	return 0;

}

void GenRandomInput(int* target, int size)
{
	int i, j;
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			target[i*size + j] = rand() % 100;
		}
	}
}

void Print2DMatrix(int* target, int size)
{
	int i, j;

	if (size >= 1) {
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++)
				printf("%d\t", target[i*size + j]);

			printf("\n");
		}
		printf("\n");
	}
	else {
		printf("[FATAL] matrix size should be larger than 0 (size: %d)\n", size);
	}
}
