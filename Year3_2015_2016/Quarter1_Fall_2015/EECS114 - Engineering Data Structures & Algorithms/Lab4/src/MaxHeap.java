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
 * Filename : MaxHeap.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
public class MaxHeap {
	//Fields
	//number of items currently in the heap
	int currentSize;
	//internal array to hold heap items
	int[] h;
	//Max size of a heap array
	public static final int CAPACITY = 100;
	
	//Constructors
	//Default constructor - Constructs an empty binary max heap.
	MaxHeap(){
		h = new int[CAPACITY];
	}
	//Constructor - Constructs a binary min heap, via buildMaxHeap(). You can use the built-in length property to determine the size of the array.
	MaxHeap(int[] A){
		h = new int[CAPACITY];
		for(int i = 0; i < A.length; i++){
			h[i] = A[i];
		}
		currentSize = A.length;
		buildMaxHeap();
	}
	//Builds a binary max heap in linear time from an unsorted array.
	void buildMaxHeap(){
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
	void heapExtractMax(){
		if(currentSize == 0){
			throw new IndexOutOfBoundsException("Heap is Empty. Cannot heapExtractMax()");
		}
		h[0] = 0;
		h[0] = h[currentSize-1];
		currentSize--;
		trickleDown(0);
	}
	//Insert key into heap. If full, throw exception.
	void maxHeapInsert(int key){
		if(currentSize == CAPACITY){
			throw new IndexOutOfBoundsException("Heap is Full.  Cannot heapInsertMax()");
		}
		else{
			h[currentSize] = key;
			trickleUp(currentSize);
		}
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
	//helper function - Maintains the heap property between a node located at index in array, and its parent. Use in maxHeapInsert(int key).
	private void trickleUp(int index){
		int x = currentSize;
		int temp = 0;
		
		while (x > 0 && h[(x-1)/2] < h[x]){
				temp = h[x];
				h[x] = h[(x-1)/2];
				h[(x-1)/2] = temp;
				x = (x-1)/2;
		}
		
		currentSize++;
	}
	//Prints heap
	void printHeap(){
		int row_counter = 0;
		int power_check = 0;
		
		for(int i = 0; i < currentSize; i++){
			System.out.print(h[i]+ " ");
			row_counter++;
			if(row_counter == Math.pow(2, power_check) && i != currentSize-1){
				System.out.print("\n");
				power_check++;
				row_counter = 0;
			}
		}
		
		System.out.print("\n\n");

	}
}
