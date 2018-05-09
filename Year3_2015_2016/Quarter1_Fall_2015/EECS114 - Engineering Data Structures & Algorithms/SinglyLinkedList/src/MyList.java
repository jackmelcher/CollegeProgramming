/**
 * Course: EECS 114 Fall 2015
 *
 * First Name: Jack
 * Last Name: Melcher
 * Lab Section: 1A
 * email address: jmelcher@uci.edu
 *
 *
 * Assignment: Assignment 1
 * Filename : MyList.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

public class MyList {
	// Node class
	private class Node {
		private char value;
		private Node next;
		public Node() { this.value = 0; this.next = null;}
		
		// Accessor methods
		public char getElement() { return value; }
		public Node getNext() { return next; }
		
		// Modifier methods
		public void setElement(char v) { value = v; }
		public void setNext(Node n) { next = n; }
	}
	
	// MyList class
	private Node head;
	
	// Implement required methods here
	//Constructor. Default
	MyList(){
		head = null;
	}
	//Constructor. Instantiates this list as a deep copy of rhs.
	MyList(MyList rhs){
		if(rhs.head != null){
			for(int i = 0; i < rhs.size(); i++){
				pushBack(rhs.get(i));
			}
		}
		else{head = null;}
		
	}
	//Constructor. Instantiates this list as a deep copy of charArray of length n.
	MyList (char[] charArray, int n){
		for(int i = 0; i < n; i++){
			pushBack(charArray[i]);
		}
	}
	//Methods
	//Removes the element at the specified position in this list. Returns true if this list contained the specified element.
	boolean remove(int index){
		Node temp = null;
		
		//Remove last element
		if(index == 0){
			popFront();
			return true;
		}
		//Remove at index of list
		else if(index > 0 && index < size()-1){
			temp = head;
			for(int i = 0; i < index-1; i++){
				temp = temp.next;
			}
			temp.next = temp.next.next;
			return true;
		}
		else if(index == size()-1){
			popBack();
			return true;
		}
		else if(index < 0 || index >= size()){
			System.out.println("Outside of index range");
		}
		
		return false;
	}
	//Removes the first occurrence of the specified element from this list,	if it is present. Returns true if this list contained the specified element.
	boolean remove(char value){
		Node temp = null;

		if(contains(value)){
			temp = head;
			if(temp.value == value){
				popFront();
				return true;
			}
			for(int i = 0; i < size(); i++){
				if(temp.value == value){
					previous(temp).next = next(temp);
					return true;
				}
				temp = temp.next;
			}
		}
		
		return false;
	}
	//Removes all occurrences of the specified element from this list, if it is present. Returns true if this list contained the specified element.
	boolean removeAll(char value){
		boolean removeAll = false;
		
		if(contains(value)){
			removeAll = true;
		}
		while(contains(value)){
			remove(value);
		}
		
		return removeAll;
	}
	//Returns the previous node for the specified node curr.
	Node previous(Node curr){
		Node temp = null;
		
		temp = head;
		if(temp == curr){
			return null;
		}
		for(int i = 0; i < size(); i++){
			if(temp.next == curr){
				break;
			}
			else{temp = temp.next;}
		}
		return temp;

	}
	//Returns the next node for the specified node curr.
	Node next(Node curr){
		return curr.next;
	}
	//Returns true if this list contains the specified value.
	boolean contains(char value){
		
		if(head != null){
			for(int i = 0; i < size(); i++){
				if(get(i) == value){
					return true;
				}
			}
		}
		return false;
	}
	//Returns the element at the specified position in this list. Index of first element in list is 0.
	char get(int index){
		Node temp = null;
		
		if(head != null){
			temp = head;
			for(int i = 0; i < index; i++){
				temp = temp.next;
			}
		}
		return temp.getElement();
	}
	//Replaces the element at the specified position in this list with the specified element.
	void set(int index, char value){
		Node temp;
		
		if(head != null){
			temp = head;
			for(int i = 0; i < index; i++){
				temp = temp.next;
			}
			temp.setElement(value);
		}
	}
	//Compares the specified MyList with this list for equality. Equal lists have exactly identical items in same order in list.
	boolean equals(MyList llist){
		boolean equals = true;
		
		if(size() == llist.size()){
			for(int i = 0; i < size(); i++){
				if(get(i) != llist.get(i)){
					equals = false;
					break;
				}
			}
		}
		else{equals = false;}
		
		return equals;
	}
	//Inserts a node with specified value at the front of the list.
	void pushFront(char value){
		Node temp = new Node();
		temp.value = value;
		
		if(head == null){
			head = temp;
		}
		else{
			temp.setNext(head);
			head = temp;	
		}
		
	}
	//Inserts a node with specified value at the back of the list.
	void pushBack(char value){
		Node temp1;
		Node temp2 = new Node();
		temp2.value = value;
		
		if(head == null){
			head = temp2;
		}
		else{
			temp1 = head;
			for(int i = 1; i < size(); i++){
				temp1 = temp1.getNext();
			}
			temp1.setNext(temp2);
		}
	}
	//Removes the front item from the list.
	void popFront(){
	
		if(head == null){
			System.out.println("List is empty.");
		}
		else{
			head = head.next;	
		}
	}
	//Removes the last item from the list.
	void popBack(){
		Node temp = null;

		if(head.next == null){
			head = null;
		}
		else{
			temp = head;
			for(int i = 1; i < size()-1; i++){
				temp = next(temp);
			}
			temp.next = null;
		}
	}
	//Swaps the value of the node at position i in the list with value of the node at position j. Be sure you handle out-of-range calls.
	void swap(int i, int j){
		char temp1 = get(i);
		char temp2 = get(j);
		
		set(i, temp2);
		set(j, temp1);
	}
	//Inserts a node with specified value at position i in the list, shifting elements starting at i to the right, if needed.
	void insertAtPos(int index, char value){
		Node temp; //temporary reference to aid in adding new node
		Node newNode = new Node(); //Create new Node
		
		
		//Add to beginning of list
		if(index == 0){
			pushFront(value);			
		}
		//Add at index of list
		else if(index > 0 && index < size()){
			temp = head;
			for(int i = 0; i < index-1; i++){
				temp = temp.next;
			}
			newNode.next = temp.next;
			temp.next = newNode;
			newNode.value = value;
			
		}
		//Add to end of list
		else if(index == size()){
			pushBack(value);
		}
		else if(index < 0 || index > size()){
			System.out.println("Outside of index range");
		}
	}
	//Inserts a node with specified value at position index+1 in the list.
	void insertAfter(int index, char value){
		insertAtPos(index+1, value);
	}
	//Inserts a node with specified value at position index-1 in the list.
	void insertBefore(int index, char value){
		insertAtPos(index-1, value);
	}
	//Returns a list object that is a portion of this list between the specified fromIndex, inclusive, and toIndex, exclusive.
	MyList subList(int fromIndex, int toIndex){
		MyList subList = new MyList();
		
		for(int i = fromIndex; i < toIndex; i++){
			subList.pushBack(get(i));
		}
		
		return subList;
	}
	//Returns the position of the first occurrence of value in this list. If the character is not in the list, the method returns -1.
	int find(char value){
		int index = -1;
		
		for(int i = 0; i < size(); i++){
			if(get(i) == value){
				index = i;
				break;
			}
		}
		return index;
	}
	//Returns the position of the first occurrence of queryStr in this list. If queryStr is not in the list, the method returns -1.
	int find(MyList queryStr){
		
		String temp1 = toString();
		String temp2 = queryStr.toString();
		
		return temp1.indexOf(temp2);

	}
	//Returns an array containing all of the items in this list in proper sequence (from first to last element).
	char[] toArray(){
		char[] charArray = new char[size()];

		if(head == null){
			return null;
		}
		else{
			for(int i = 0; i < size(); i++){
				charArray[i] = get(i);
			}
			return charArray;
		}
	}
	//Reverses the items in the list.
	void reverse(){
		char[] temp1;
		Node temp2 = null;
		
		temp1 = toArray();
		if(head != null){
			temp2 = head;
			for(int i = 0; i < size(); i++){
				temp2.value = temp1[size()-1-i];
				temp2 = temp2.next;
			}
		}
	}
	//Returns the number of items in the list.
	int size(){
		int size = 0;
		Node temp = null;
		
		if(head != null){
			temp = head;
			size++;
			while(temp.next != null){
				temp = temp.next;
				size++;
			}
		}
		return size;
	}
	//Prints the contents of the list. Allows for printing a MyList instance llist to standard output in following way, llist.print();
	void print(){
		if(head != null){
			for(int i = 0; i < size(); i++){
				System.out.print(""+get(i));
			}
			System.out.print("\n");
		}
		else{System.out.println("List is Empty");}
	}
	/*Overrides the toString() method. Returns the formatted contents of this as a
	String. Allows for printing a MyList instance llist to standard output in following way,
	System.out.println("llist contents = " + llist);*/
	public String toString(){
		String str = new String();
		for(int i = 0; i < size(); i++){
			str = ""+str+get(i);
		}
		return str;
	}
	
	
}
