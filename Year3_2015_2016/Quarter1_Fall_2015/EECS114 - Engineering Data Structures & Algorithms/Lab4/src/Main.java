import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * Course: EECS 114 Fall 2015
 *
 * First Name: Jack
 * Last Name: Melcher
 * Lab Section: 1A
 * email address: jmelcher@uci.edu
 *
 *
 * Assignment: Lab 4
 * Filename : Main.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
public class Main {

	public static void main(String[] args) throws FileNotFoundException{
		
		int[] test1 = {10,7,14,9,8,6,12,2,19};
		int[] test2 = {1,14,13,16,23,19,17};
		MinHeap minheap;
		MaxHeap maxheap;

		//Tests for when heaps are empty
		minheap = new MinHeap();
		try {
			System.out.println("minHeap key = "+minheap.heapMin());
		} catch (IndexOutOfBoundsException e) {
		    System.err.println("IndexOutOfBoundsException: " + e.getMessage());
		}
		try {
			minheap.heapExtractMin();
		} catch (IndexOutOfBoundsException e) {
		    System.err.println("IndexOutOfBoundsException: " + e.getMessage());
		}
		maxheap = new MaxHeap();
		try {
			System.out.println("maxHeap key = "+maxheap.heapMax());
		} catch (IndexOutOfBoundsException e) {
		    System.err.println("IndexOutOfBoundsException: " + e.getMessage());
		}
		try {
			maxheap.heapExtractMax();
		} catch (IndexOutOfBoundsException e) {
		    System.err.println("IndexOutOfBoundsException: " + e.getMessage());
		}
		
		//Tests for when heaps are full
		minheap = new MinHeap();
		for(int i = 1; i <= 101; i++){
			try {
				minheap.minHeapInsert(i);;
			} catch (IndexOutOfBoundsException e) {
			    System.err.println("IndexOutOfBoundsException: " + e.getMessage());
			}
		}

		maxheap = new MaxHeap();
		for(int i = 1; i <= 101; i++){
			try {
				maxheap.maxHeapInsert(i);;
			} catch (IndexOutOfBoundsException e) {
			    System.err.println("IndexOutOfBoundsException: " + e.getMessage());
			}
		}
		
		
		System.out.println("Test: MinHeap insert in order");
		minheap = new MinHeap();
		minheap.minHeapInsert(1);
		minheap.minHeapInsert(2);
		minheap.minHeapInsert(3);
		minheap.minHeapInsert(4);
		minheap.minHeapInsert(5);
		minheap.minHeapInsert(6);
		minheap.minHeapInsert(7);
		minheap.printHeap();
		System.out.println("minHeap key = "+minheap.heapMin());

		System.out.println("Test: MinHeap insert in reverse order");
		minheap = new MinHeap();
		minheap.minHeapInsert(7);
		minheap.minHeapInsert(6);
		minheap.minHeapInsert(5);
		minheap.minHeapInsert(4);
		minheap.minHeapInsert(3);
		minheap.minHeapInsert(2);
		minheap.minHeapInsert(1);
		minheap.printHeap();
		
		System.out.println("Test: Building MinHeap");
		minheap = new MinHeap(test1);
		minheap.printHeap();

		System.out.println("Test: Remove MinHeap");
		minheap = new MinHeap(test2);
		System.out.println("minHeap key = "+minheap.heapMin());
		minheap.printHeap();
		minheap.heapExtractMin();
		System.out.println("minHeap key = "+minheap.heapMin());
		minheap.printHeap();
		minheap.heapExtractMin();
		System.out.println("minHeap key = "+minheap.heapMin());
		minheap.printHeap();		
		
		System.out.println("Test: MaxHeap insert in order");
		maxheap = new MaxHeap();
		maxheap.maxHeapInsert(1);
		maxheap.maxHeapInsert(2);
		maxheap.maxHeapInsert(3);
		maxheap.maxHeapInsert(4);
		maxheap.maxHeapInsert(5);
		maxheap.maxHeapInsert(6);
		maxheap.maxHeapInsert(7);
		maxheap.printHeap();
		System.out.println("maxHeap key = "+maxheap.heapMax());

		System.out.println("Test: MaxHeap insert in reverse order");
		maxheap = new MaxHeap();
		maxheap.maxHeapInsert(7);
		maxheap.maxHeapInsert(6);
		maxheap.maxHeapInsert(5);
		maxheap.maxHeapInsert(4);
		maxheap.maxHeapInsert(3);
		maxheap.maxHeapInsert(2);
		maxheap.maxHeapInsert(1);
		maxheap.printHeap();
		
		System.out.println("Test: Building MaxHeap");
		maxheap = new MaxHeap(test1);
		maxheap.printHeap();
		
		System.out.println("Test: Remove MaxHeap");
		maxheap = new MaxHeap(test2);
		System.out.println("maxHeap key = "+maxheap.heapMax());
		maxheap.printHeap();
		maxheap.heapExtractMax();
		System.out.println("maxHeap key = "+maxheap.heapMax());
		maxheap.printHeap();
		maxheap.heapExtractMax();
		System.out.println("maxHeap key = "+maxheap.heapMax());
		maxheap.printHeap();

		int[] test3 = new int[10];
		int i = 0;
		File text = new File("input_int_small.txt");
		try {
			Scanner inNums = new Scanner(text);
			while(inNums.hasNextInt()) {
				test3[i] = inNums.nextInt();
				i++;
			}
			inNums.close();
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
		}
		System.out.println("Test: minheap for input_int_small");
		minheap = new MinHeap(test3);
		minheap.printHeap();
		
		System.out.println("Test: maxheap for input_int_small");
		maxheap = new MaxHeap(test3);
		maxheap.printHeap();
		/*
		int[] test3 = new int[10000];
		int i = 0;
		File text = new File("input_int_large.txt");
		try {
			Scanner inNums = new Scanner(text);
			while(inNums.hasNextInt()) {
				test3[i] = inNums.nextInt();
				i++;
			}
			inNums.close();
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
		}
		System.out.println("Test: minheap for input_int_large");
		minheap = new MinHeap(test3);
		minheap.printHeap();
		
		System.out.println("Test: maxheap for input_int_large");
		maxheap = new MaxHeap(test3);
		maxheap.printHeap();
		 */
	}

}
