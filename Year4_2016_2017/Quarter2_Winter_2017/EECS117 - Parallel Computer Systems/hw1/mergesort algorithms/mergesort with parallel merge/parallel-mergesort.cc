/**
*  \file parallel-mergesort.cc
*
*  \brief Implement your parallel mergesort in this file.
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <omp.h>

#include "sort.hh"

keytype* mergesort(keytype* A, int N);
keytype* pmerge(keytype* A, int nA, keytype* B, int nB);
int binsearch(keytype* A, int N, int T);


void parallelSort(int N, keytype* A) {
	/* Lucky you, you get to start from scratch */
	int i = 0;
	keytype* unsorted = newCopy(N, A);
	keytype* sorted;

	/*
	//Print array pre sort
	for (i = 0; i < N; i++)
		printf("A[%d] = %d\n", i, A[i]);
	printf("\n");
	*/

	sorted = mergesort(unsorted, N);

	//Copy values over to memory referenced by A
	#pragma omp parallel for shared (A,N,sorted) private (i)
	for (i = 0; i < N; i++)
		A[i] = sorted[i];

	/*
	//Print array post sort
	for (i = 0; i < N; i++)
		printf("A[%d] = %d\n", i, A[i]);
	*/

	free(unsorted);
	free(sorted);
}

//Parallel merge sort
keytype* mergesort(keytype* A, int N) {
	int a = 0;

	int q = (N - 1) / 2;

	int n1 = q + 1;
	int n2 = N - 1 - q;
	
	keytype* L = newKeys(n1);
	keytype* R = newKeys(n2);
	keytype* sorted = NULL;

	if (N <= 1) {
		return A;
	}
	else{//if (N > 1)
		//Copy values into left and right arrays
		//Left Array
		//printf("n1 = %d\n", n1);
		for (a = 0; a < n1; a++) {
			L[a] = A[a];
			//printf("L[%d] = %d\n", a, L[a]);
		}
		//printf("\n");
		//Right Array
		//printf("n2 = %d\n", n2);
		for (a = n1; a < N; a++) {
			R[a - n1] = A[a];
			//printf("R[%d] = %d\n", a - n1, R[a - n1]);
		}
		//printf("\n");

		#pragma omp parallel sections
		{
			#pragma omp section
				L = mergesort(L, n1);
			#pragma omp section
				R = mergesort(R, n2);
		}

		//Parallel Merge
		//Return a fully sorted array when given two separate sorted arrays
		//printf("Starting Parallel Merge\n");
		sorted = pmerge(L, n1, R, n2);
		
		//Free temp arrays
		free(L);
		free(R);
	
		return sorted;
	}
}

//Parallel merge
keytype* pmerge(keytype* A, int nA, keytype* B, int nB) {
	int i = 0;

	int midpoint_index = 0;
	int v = 0, k = 0;

	keytype* temp = NULL;
	int ntemp = 0;
	
	keytype* C1 = NULL;
	int nC1 = 0;
	keytype* C2 = NULL;
	int nC2 = 0;
	
	keytype* D1 = NULL;
	int nD1 = 0;
	keytype* D2 = NULL;
	int nD2 = 0;
	
	keytype* E1 = NULL;
	int nE1 = 0;
	keytype* E2 = NULL;
	int nE2 = 0;
	
	keytype* sorted = NULL;
	int nsorted = nA + nB;

	//Check if arrays arent NULL
	if (A == NULL && B != NULL) {
		return B;
	}
	else if (A != NULL && B == NULL) {
		return A;
	}
	else if (A == NULL && B == NULL) {
		return NULL;
	}
	else {//default approach
		//Swap A and B and their sizes if B is larger than A
		if (nA < nB) {
			//Swap arrays
			temp = B;
			B = A;
			A = temp;
			temp = NULL;

			//Swap sizes
			ntemp = nB;
			nB = nA;
			nA = ntemp;
			ntemp = 0;
		}

		//Check base case of array size = 1
		if (nA > 1) {
			/*
			printf("Pmerge Default case\n");
			printf("nA = %d, nB = %d\n", nA, nB);
			for (i = 0; i < nA; i++) {
				printf("A[%d] = %d\n", i, A[i]);
			}
			for (i = 0; i < nB; i++) {
				printf("B[%d] = %d\n", i, B[i]);
			}
			printf("nsorted = %d\n", nsorted);
			*/
			midpoint_index = (nA - 1) / 2;
			v = A[midpoint_index];
			k = binsearch(B, nB, v);

			//make sure binary search index k isnt larger than size of B
			//if k <= 0, D1 will be NULL
			//if k >= nB, D2 will be NULL
			//if k is n index between 0 and nB, nothing should be NULL
			
			//Make new arrays
			nC1 = ((nA - 1) / 2) + 1;
			C1 = newKeys(nC1);

			nC2 = nA - 1 - ((nA - 1) / 2);
			C2 = newKeys(nC2);

			nD1 = k;
			if (nD1 > 0){
				D1 = newKeys(nD1);
			}
			nD2 = nB - k;
			if (nD2 > 0) {
				D2 = newKeys(nD2);
			}

			//Place values in arrays
			//C1
			for (i = 0; i < nC1; i++) {
				C1[i] = A[i];
			}
			//C2
			for (i = nC1; i < nA; i++) {
				C2[i - nC1] = A[i];
			}
			//D1
			for (i = 0; i < nD1; i++) {
				D1[i] = B[i];
			}
			//D2
			for (i = nD1; i < nB; i++) {
				D2[i - nD1] = B[i];
			}

			nE1 = nC1 + nD1;
			nE2 = nC2 + nD2;
			//E1 = newKeys(nE1);
			//E2 = newKeys(nE2);

			//Can be parallel here
			#pragma omp parallel sections
			{
				#pragma omp section
					E1 = pmerge(C1, nC1, D1, nD1);
				#pragma omp section
					E2 = pmerge(C2, nC2, D2, nD2);
			}
			// end of parallel
			
			//print check on E1 and E2
			/*
			printf("nE1 = %d\n", nE1);
			for (i = 0; i < nE1; i++) {
				printf("E1[%d] = %d\n", i, E1[i]);
			}
			printf("nE2 = %d\n", nE2);
			for (i = 0; i < nE2; i++) {
				printf("E2[%d] = %d\n", i, E2[i]);
			}
			*/
			//Combine E1 and E2 into sorted
			sorted = newKeys(nsorted);
			for (i = 0; i < nE1; i++) {
				sorted[i] = E1[i];
				//printf("sorted[%d] = %d\n", i, sorted[i]);
			}
			for (i = 0; i < nE2; i++) {
				sorted[i+nE1] = E2[i];
				//printf("sorted[%d] = %d\n", i + nE1, sorted[i + nE1]);
			}
			/*
			for (i = 0; i < nsorted; i++) {
				printf("sorted[%d] = %d\n", i, sorted[i]);
			}
			*/
			//Free all temporary memory
			
			if (C1 != NULL)
				free(C1);
			if (C2 != NULL)
				free(C2);
			if (D1 != NULL)
				free(D1);
			if (D2 != NULL)
				free(D2);
			//if (E1 != NULL)
			//	free(E1);
			//if (E2 != NULL)
			//	free(E2);
			
		}
		else {//when both are of array size 1, determine correct order and return that instead
			/*
			printf("Pmerge Base case\n");
			printf("nA = %d, nB = %d\n", nA, nB);
			printf("A[0] = %d, B[0] = %d\n", A[0], B[0]);
			
			printf("nsorted = %d\n", nsorted);
			*/
			sorted = newKeys(nsorted);

			if (A[0] <= B[0]) {
				sorted[0] = A[0];
				sorted[1] = B[0];
				//printf("sorted[0] = %d\n", sorted[0]);
				//printf("sorted[1] = %d\n", sorted[1]);
			}
			else {
				sorted[0] = B[0];
				sorted[1] = A[0];
				//printf("sorted[0] = %d\n", sorted[0]);
				//printf("sorted[1] = %d\n", sorted[1]);
			}
		}
	}



	return sorted;	
}

int binsearch(keytype* A, int N, int T) {
	int L = 0, R = N - 1;
	int M = 0;

	while (L <= R) {
		M = (L + R) / 2;

		if (A[M] < T) {
			L = M + 1;
		}
		else if (A[M] > T) {
			R = M - 1;
		}
		else {//A[M] == T
			//successful search
			return M;
		}
	}
	//unsuccessful search
	return L;
}

/* eof */
