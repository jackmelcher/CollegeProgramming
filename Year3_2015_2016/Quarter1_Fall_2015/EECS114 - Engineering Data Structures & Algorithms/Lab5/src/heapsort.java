import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
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
 * Assignment: Lab 5
 * Filename : heapsort.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
public class heapsort {
	public static final int CAPACITY = 100;
	int[] h = new int[CAPACITY] , sortedHeap = new int[CAPACITY] ;
	int initialLength = 0;
	int currentSize;
	
	public heapsort(int[] array, int length){
		//Create new heap array
		h = new int[CAPACITY];
		for(int i = 0; i < length; i++){
			h[i] = array[i];
		}
		currentSize = length;
		initialLength = length;
		BuildMaxHeap();
		printHeap();
		//Heap sorting begins
		for(int i = length; i > 1; i--){
			sortedHeap[currentSize - 1] = heapMax();
			MaxHeapify();
			printHeap();
		}
		sortedHeap[currentSize - 1] = heapMax();
		MaxHeapify();
	}
	//Builds a binary max heap in linear time from an unsorted array.
	public void BuildMaxHeap(){
		for (int i = (currentSize/2)-1; i >= 0; i--)
			trickleDown(i);
	}
	
	//Returns the maximum key in the heap. If empty, throw exception.
	int heapMax(){
		if(currentSize == 0){
			throw new IndexOutOfBoundsException("Heap is Empty. Cannot return max key");
		}
		return h[0];
	}
	//Removes maximum key from heap. If empty, throw exception.
	void MaxHeapify(){
		if(currentSize == 0){
			throw new IndexOutOfBoundsException("Heap is Empty. Cannot heapExtractMax()");
		}
		h[0] = 0;
		h[0] = h[currentSize-1];
		currentSize--;
		trickleDown(0);
	}
	//helper function - Maintains the heap property between a parent node located at index in array, and its children. Used in buildMaxHeap().
	private void trickleDown(int index){
		int temp;

		while(index <= (currentSize/2)-1){
			//Compare key of parent to children
			if(h[index] < h[2*index + 1] || h[index] < h[2*index + 2]){
				//if left child is largest, swap parent with left child
				if(h[2*index + 1] > h[2*index + 2]){
					temp = h[index];
					h[index] = h[2*index + 1];
					h[2*index + 1] = temp;
					index = 2*index + 1;
				}
				//if right child is largest, swap parent with right child
				else if(h[2*index + 1] < h[2*index + 2]){
					temp = h[index];
					h[index] = h[2*index + 2];
					h[2*index + 2] = temp;
					index = 2*index + 2;
				}
			}
			else{break;}
		}
	}
	//Prints heap
	void printHeap(){
		//System.out.println("CurrentSize = "+currentSize);
		//printing max heap
		for(int i = 0; i < currentSize; i++){
			System.out.print(h[i]+ " ");
		}
		//printing sorted heap
		for(int j = currentSize; j < initialLength; j++ ){
			System.out.print(sortedHeap[j]+ " ");
		}
		System.out.print("\n");

	}
	
	//Main method for all the testing
	public static void main(String[] args) throws FileNotFoundException {

		int array[] = new int[CAPACITY];
		int length = 0;
		
		if(args.length < 1 || args.length > 1){
			System.out.println("Exectue using the following format");
			System.out.println("java heapsort input_file");
		}
		else if(args.length == 1){
			Scanner s = new Scanner(new FileReader(args[0]));
			
			int i = 0;

			if(s.hasNextInt()){
				//First value in input.txt is the number of values in the array
				length = s.nextInt();
				//System.out.println(""+length);
				//Rest of values in input.txt are values to put in array
				while (s.hasNextInt()) {
					array[i] = s.nextInt();
					//System.out.println(""+array[i]);
					i++;
				}
			}			
			s.close();
			
			heapsort heapToSort = new heapsort(array, length);

						
		}
	}

}
