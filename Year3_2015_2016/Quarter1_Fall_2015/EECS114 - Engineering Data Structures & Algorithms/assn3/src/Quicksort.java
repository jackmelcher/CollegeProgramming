import java.util.Random;
import java.util.Vector;

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
 * Filename : Quicksort.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
public class Quicksort {
	//Fields
	
	//Constructor
	public Quicksort(){
		
	}
	
	//Methods
	public int[] quicksort(int[] unsorted_array, String pivot){
		int p = 0;
		Vector<Integer> L = new Vector<Integer>();
		Vector<Integer> G = new Vector<Integer>();
		Vector<Integer> Sorted = new Vector<Integer>();

		//Pivot Selection
		if(pivot.compareTo("first") == 0){
			p = unsorted_array[0];
		}
		else if(pivot.compareTo("random") == 0){
			Random rand = new Random();
			
			p = unsorted_array[rand.nextInt(unsorted_array.length)];
		}
		else if(pivot.compareTo("median3") == 0 && unsorted_array.length >= 3){
			int a = 0, b = 0, c = 0;
			int a_index, b_index, c_index;
			Random rand = new Random();
			
			//Select random indices that are not the same
			a_index = rand.nextInt(unsorted_array.length);
			
			do{
				b_index = rand.nextInt(unsorted_array.length);
			}while(b_index == a_index);
			
			do{
				c_index = rand.nextInt(unsorted_array.length);
			}while(c_index == a_index || c_index == b_index);
			
			//Assign the values to a, b, and c
			a = unsorted_array[a_index];
			b = unsorted_array[b_index];
			c = unsorted_array[c_index];

			//Determine the median of the three
			//a is median
			if(a <= b && a >= c || a >= b && a <= c){
				p = a;
			}
			//b is median
			else if(b <= a && b >= c || b >= a && b <= c){
				p = b;
			}
			//c is median
			else if(c <= b && c >= a || c >= b && c <= a){
				p = c;
			}
		}
		else if(pivot.compareTo("dqselect") == 0 && unsorted_array.length%5 == 0){
			int numberOfSubarrays = unsorted_array.length/5;
			
			//Separate unsorted_array into n/5 groups of arrays that are of size 5
			//Use insertion sort to sort each array
			for(int i = 0; i < numberOfSubarrays; i++){
				for(int j = 1+5*i; j < 5*(i+1); j++){
					//Insertion Sort
					for(int k = j; k > 1+5*i; k--){
						if(unsorted_array[k-1] > unsorted_array[k]){
							int temp = unsorted_array[k];
							unsorted_array[k] = unsorted_array[k-1];
							unsorted_array[k-1] = temp;
						}
					}
				}
			}
			/*
			for(int i = 0; i < unsorted_array.length; i++){
				System.out.print(unsorted_array[i]+", ");
			}
			System.out.print("\n ");
			*/
			
			//find medians of each array and insert them into another array
			int[] array1 = new int[numberOfSubarrays];
			for(int i = 0; i < numberOfSubarrays; i++){
				array1[i] = unsorted_array[2+i*5];
			}
			//Find Median of Medians using Insertion Sort
			for(int i = 1; i < array1.length; i++){
				for(int j = i; j > 0; j--){
					if(array1[j-1] > array1[j]){
						int temp = array1[j];
						array1[j] = array1[j-1];
						array1[j-1] = temp;
					}
				}
			}
			/*
			for(int i = 0; i < array1.length; i++){
				System.out.print(array1[i]+", ");
			}
			*/
			
			//Assign pivot value. Even size arrays pick lower median.
			p = array1[(array1.length-1)/2];
			//System.out.println("Median: "+p);			
		}
		else{
			//default to first
			p = unsorted_array[0];
		}
		
		//Partition
		for(int i = 0; i < unsorted_array.length; i++){
			if(unsorted_array[i] < p){
				L.add(unsorted_array[i]);
			}
			else if(unsorted_array[i] > p){
				G.add(unsorted_array[i]);
			}
			else{
				Sorted.add(unsorted_array[i]);
			}
			
		}
		
		//Recursive call of elements less than pivot
		int[] l = new int[L.size()];
		if(L.size() > 0){
			for(int i = 0; i < l.length; i++){
				l[i] = L.get(i);
			}
			l = quicksort(l,pivot);
		}
		/*
		System.out.println("Elements are: ");  
		for (int i = 0; i < l.length; i++) {
			System.out.println(l[i]);
		}
		*/
		
		//Recursive call of elements greater than pivot
		int[] g = new int[G.size()];
		if(G.size() > 0){
			for(int i = 0; i < g.length; i++){
				g[i] = G.get(i);
			}
			g = quicksort(g,pivot);
		}
		/*
		System.out.println("Elements are: ");  
		for (int i = 0; i < g.length; i++) {
			System.out.println(g[i]);
		}
		*/
		
		//Join L, G with Sorted vectors
		if(L.size() > 0){
			for(int i = l.length-1; i >= 0; i--){
				Sorted.add(0, l[i]);
			}
		}
		if(G.size() > 0){
			for(int i = 0; i < g.length; i++){
				Sorted.add(Sorted.size(), g[i]);
			}
		}
		//Convert Sorted vector to array
		int[] sorted = new int[Sorted.size()];
		for(int i = 0; i < sorted.length; i++){
			sorted[i] = Sorted.get(i);
		}
		/*
		System.out.println("Elements are: ");  
		for (int i = 0; i < sorted.length; i++) {
			System.out.println(sorted[i]);
		}
		*/
		return sorted;
	}
}
