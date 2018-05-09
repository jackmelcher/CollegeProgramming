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
 * Assignment: Assignment 4
 * Filename : PriorityQueue.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
public class PriorityQueue {
	//Fields
	//number of items currently in the heap
	int currentSize = 0;
	//internal array to hold heap items
	Node[] h;
	//Max size of a heap array
	public static final int CAPACITY = 100;
	
	private static class Node{
		//Vertex Fields
		int item;
		int key;
		//Vertex Constructors
		Node(int item, int key){
			this.item = item;
			this.key = key;
		}
		//Vertex Methods
	}
	
	//Constructors
	//Default constructor - Constructs an empty binary min heap.
	PriorityQueue(){
		h = new Node[CAPACITY];
	}
	
	//Methods
	//Builds a binary min heap in linear time from an unsorted array.
	void buildMinHeap(){
		for (int i=(currentSize/2)-1; i >= 0; i--){
			trickleDown(i);
		}
	}
	//Returns the minimum key in the heap. If empty, throw exception.
	Node top(){
		if(currentSize == 0){
			throw new IndexOutOfBoundsException("Heap is Empty. Cannot return min key");
		}
		return h[0];
	}
	//Removes minimum key from heap. If empty, throw exception.
	void pop(){
		if(currentSize == 0){
			throw new IndexOutOfBoundsException("Heap is Empty. Cannot heapExtractMin()");
		}
		h[0] = h[currentSize-1];
		currentSize--;
		trickleDown(0);
	}
	//Insert key into heap. If full, throw exception.
	void push(int item, int key){
		if(currentSize == CAPACITY){
			throw new IndexOutOfBoundsException("Heap is Full. Cannot heapInsertMin()");
		}
		//else if(item already exists in priority queue){
		
		//}
		else{
			int itemAlreadyExistsIndex = itemExistanceTest(item);
			if(itemAlreadyExistsIndex > -1){//change key in already existing item
				//	if key increases, trickle down
				if(key > h[itemAlreadyExistsIndex].key){
					h[itemAlreadyExistsIndex].key = key;
					trickleDown(itemAlreadyExistsIndex);
				}
				//	if key decreases, trickle up
				if(key < h[itemAlreadyExistsIndex].key){
					h[itemAlreadyExistsIndex].key = key;
					trickleUp(itemAlreadyExistsIndex);
				}
			}
			else{//insert new item into priority queue
				Node newNode = new Node(item, key);
				h[currentSize] = newNode;
				trickleUp(currentSize);
			}
		}
	}
	//helper function - Maintains the heap property between a parent node located at index in array, and its children. Used in buildMinHeap().
	private void trickleDown(int index){
		Node temp;

		while(index <= (currentSize/2)-1){
			//Compare key of parent to children
			if(h[index].key > h[2*index + 1].key || h[index].key > h[2*index + 2].key){
				//if left child is smallest, swap parent with left child
				if(h[2*index + 1].key < h[2*index + 2].key || h[2*index + 2].key == 0){
					temp = h[index];
					h[index] = h[2*index + 1];
					h[2*index + 1] = temp;
					index = 2*index + 1;
				}
				//if right child is smallest, swap parent with right child
				else if(h[2*index + 1].key > h[2*index + 2].key || h[2*index + 1].key == 0){
					temp = h[index];
					h[index] = h[2*index + 2];
					h[2*index + 2] = temp;
					index = 2*index + 2;
				}
			}
			else{break;}
		}
	}
	//helper function - Maintains the heap property between a node located at index in array, and its parent. Use in minHeapInsert(int key).
	private void trickleUp(int index){
		int x = index;
		Node temp;
		
		while (x > 0 && h[(x-1)/2].key > h[x].key){
				temp = h[x];
				h[x] = h[(x-1)/2];
				h[(x-1)/2] = temp;
				x = (x-1)/2;
		}
		if(index == currentSize){
			currentSize++;
		}
	}
	
	int itemExistanceTest(int item){
		boolean existance = false;
		int index = 0;
		
		for(int i = 0; i < currentSize; i++){
			if(item == h[i].item){
				existance = true;
				index = i;
				break;
			}
		}
		if(existance){
			return index;
		}
		else{
			return -1;
		}

	}
	
	//Prints heap
	void print(){
		int row_counter = 0;
		int power_check = 0;
		
		for(int i = 0; i < currentSize; i++){
			System.out.print(h[i].item+","+h[i].key+" ");
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
