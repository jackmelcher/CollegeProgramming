/**
 * Course: EECS 114 Fall 2015
 *
 * First Name: Jack
 * Last Name: Melcher
 * Lab Section: 1A
 * email address: jmelcher@uci.edu
 *
 *
 * Assignment: Assignment 3
 * Filename : Main.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
public class Main {
	public static void main(String[] args) {

		int[] sorted = null;

		//Quicksort Tests
		Quicksort q = new Quicksort();

		int[] a = {7, 2, 9, 4, 3, 7, 6, 1};
		sorted = q.quicksort(a, "first");
		System.out.println("Elements are: ");  
		for (int i = 0; i < sorted.length; i++) {
			System.out.println(sorted[i]);
		}
		
		int[] b = {15, 11, 15, 10, 19, 1, 7, 2, 16, 3};
		sorted = q.quicksort(b, "random");
		System.out.println("Elements are: ");  
		for (int i = 0; i < sorted.length; i++) {
			System.out.println(sorted[i]);
		}

		int[] c = {8,4,19,13,5,11,14,9,18,4};
		sorted = q.quicksort(c, "median3");
		System.out.println("Elements are: ");  
		for (int i = 0; i < sorted.length; i++) {
			System.out.println(sorted[i]);
		}
		
		int[] d = {1, 15, 12, 10, 2, 3, 13, 9, 4, 5, 6, 14, 8, 11, 17};
		sorted = q.quicksort(d, "dqselect");

		System.out.println("Elements are: ");  
		for (int i = 0; i < sorted.length; i++) {
			System.out.println(sorted[i]);
		}
		
		//Mergesort Tests
		Mergesort m = new Mergesort();
		int[] e = {7, 2, 9, 4, 3, 8, 6, 1}, b_sorted;
		sorted = m.mergesort(e);
		System.out.println("Elements are: ");  
		for (int i = 0; i < sorted.length; i++) {
			System.out.println(sorted[i]);
		}
		
		int[] f = {3, 5, 4, 9, 2};
		sorted = m.mergesort(f);
		System.out.println("Elements are: ");  
		for (int i = 0; i < sorted.length; i++) {
			System.out.println(sorted[i]);
		}
	}
}
