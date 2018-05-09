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
 * Filename : Mergesort.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
public class Mergesort {

	//Fields
	
	//Constructor
	public Mergesort(){

	}
	
	//Methods
	public int[] mergesort(int[] unsorted){
		int[] left = null, right = null, sorted = null;
		
		/*
		System.out.println("Unsorted Array:");
		for(int i = 0; i < unsorted.length; i++){
			System.out.println(unsorted[i]+", ");
		}
	*/
		
		//Check for base case
		if(unsorted.length > 1){
			left = new int[unsorted.length/2];
			right = new int[unsorted.length - unsorted.length/2];
			
			//Split array into left and right
			for(int i = 0; i < unsorted.length/2; i++){
				left[i] = unsorted[i];
			}
			for(int i = unsorted.length/2; i < unsorted.length; i++){
				right[i - unsorted.length/2] = unsorted[i];
			}	

			//perform mergesort on these subarrays
			left = mergesort(left);
			right = mergesort(right);

			//combine the arrays together
			sorted = merge(left,right);
		}
		else{
			sorted = unsorted;
		}
		
		/*
		System.out.println("Sorted Array:");
		for(int i = 0; i < sorted.length; i++){
			System.out.println(sorted[i]+", ");
		}
		*/
		
		return sorted;
	}
	
	public int[] merge(int[] left, int[] right){
		int[] merged = new int[left.length + right.length];
		
		int i = 0, j = 0, k= 0;
		while(i < left.length || j < right.length){
			//Insert right if left has already been completed
			if(i == left.length){
				merged[k] = right[j];
				j++;
				k++;
			}
			//Insert left if right has already been completed
			else if(j == right.length){
				merged[k] = left[i];
				i++;
				k++;
			}
			//Insert left if it's less than right
			else if(left[i] < right[j]){
				merged[k] = left[i];
				i++;
				k++;
			}
			//Insert right if it's less than left
			else if(left[i] > right[j]){
				merged[k] = right[j];
				j++;
				k++;
			}
			//insert both if they are equal
			else{
				merged[k] = left[i];
				i++;
				k++;
				merged[k] = right[j];
				j++;
				k++;
			}
		}
		
		return merged;
	}
}
