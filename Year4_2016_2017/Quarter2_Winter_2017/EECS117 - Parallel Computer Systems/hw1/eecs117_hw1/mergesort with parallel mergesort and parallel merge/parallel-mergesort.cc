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

void pmergesort(keytype* A, int p, int r, keytype* B, int s);
void pmerge(keytype* T, int p1, int r1, int p2, int r2, keytype* A, int p3);
int binsearch(int x, keytype* T, int p, int r);


void parallelSort(int N, keytype* A) {
	/* Lucky you, you get to start from scratch */
	int i = 0;
	keytype* B = newKeys(N);

	omp_set_num_threads(8);
	/*
	for (i = 0; i < N; i++) {
		printf("A[%d] = %d\n", i, A[i]);
	}
	*/
	#pragma omp parallel
	#pragma omp single nowait
	pmergesort(A, 0, N-1, B, 0);

	#pragma omp parallel for
	for (i = 0; i < N; i++) {
		A[i] = B[i];
		//printf("B[%d] = %d\n", i, B[i]);
	}

	free(B);
}

//Parallel merge sort
void pmergesort(keytype* A, int p, int r, keytype* B, int s) {
	
	keytype* T;
	int n, q, qprime;

	//printf("Pmergesort\n");

	n = r - p + 1;

	if (n == 1) {
		B[s] = A[p];
	}
	else {
		T = newKeys(n);
		q = (p + r) / 2;
		qprime = q - p + 1;

		#pragma omp task
		pmergesort(A, p, q, T, 0);
		pmergesort(A, q + 1, r, T, qprime);
		#pragma omp taskwait
		
		#pragma omp parallel
		#pragma omp single nowait
		pmerge(T, 0, qprime-1, qprime, n-1, B, s);
	
		free(T);
	}
}

//Parallel merge
void pmerge(keytype* T, int p1, int r1, int p2, int r2, keytype* A, int p3) {
	
	int temp, n1, n2, q1, q2, q3;

	//printf("Pmerge\n");

	n1 = r1 - p1 + 1;
	n2 = r2 - p2 + 1;
	
	//ensure that n1 >= n2
	if (n1 < n2) {
		temp = p2;
		p2 = p1;
		p1 = temp;

		temp = r2;
		r2 = r1;
		r1 = temp;

		temp = n2;
		n2 = n1;
		n1 = temp;
	}

	//both empty?
	if (n1 == 0) {
		return;
	}
	else {
		q1 = (p1 + r1) / 2;
		q2 = binsearch(T[q1], T, p2, r2);
		q3 = p3 + (q1 - p1) + (q2 - p2);
		A[q3] = T[q1];

		#pragma omp task
		pmerge(T, p1, q1 - 1, p2, q2 - 1, A, p3);
		pmerge(T, q1 + 1, r1, q2, r2, A, q3 + 1);
		#pragma omp taskwait

	}
}

/*
The procedure BINARY-SEARCH(x, T, p, r) takes a key x and a subarray T[p...r], and it returns one of the following:
	If T[p] is empty (r < p), then it returns the index p.
	
	If x <= T[p], and hence less than or equal to all the elements of T[p...r], then
	it returns the index p.
	
	If x > T[p], then it returns the largest index q in the range p < q <= r + 1 such
	that T[q-1] < x.

	Here is the pseudocode:
	BINARY-SEARCH(x, T, p, r)
	1 low = p
	2 high = max(p,r+1)
	3 while low < high
	4	mid = (low + high)/2
	5	if x <= T[mid]
	6		high = mid
	7	else low = mid + 1
	8 return high
*/

int binsearch(int x, keytype* T, int p, int r) {
	int low, mid, high;

	if (T == NULL) {
		return p;
	}
	if (x <= T[p]) {
		return p;
	}

	low = p; 
	high = r;
	
	while (low <= high) {
		mid = (low + high) / 2;

		if (T[mid] < x) {
			low = mid + 1;
		}
		else if (T[mid] > x) {
			high = mid - 1;
		}
		else {//T[mid] == x
			  //successful search
			return mid;
		}
	}
	//unsuccessful search
	return low;
}

/* eof */
