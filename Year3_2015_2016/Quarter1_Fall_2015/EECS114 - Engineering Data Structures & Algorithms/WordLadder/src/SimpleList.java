/**
 * Course: EECS 114 Fall 2015
 *
 * First Name: Jack
 * Last Name: Melcher
 * Lab Section: 1A
 * email address: jmelcher@uci.edu
 *
 *
 * Assignment: Assignment 2
 * Filename : SimpleList.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
public class SimpleList<T> {
	
	// Node class
	@SuppressWarnings("hiding")
	private class Node<T> {
		//Node Fields
		private T value;
		private Node<T> next;
		//Node Constructors
		public Node() { 
			this.value = null;
			this.next = null;
		}
		// Accessor methods
		public T getElement() { return value; }
		public Node<T> getNext() { return next; }
		
		// Modifier methods
		public void setElement(T v) { value = v; }
		public void setNext(Node<T> n) { next = n; }
	}
	
	// MyList Fields
	private Node<T> head;
	
	// MyList Constructors
	//Constructor. Default
	SimpleList(){
		head = null;
	}
	//Constructor. Instantiates this list as a deep copy of rhs.
	SimpleList(SimpleList<T> rhs){
		Node<T> temp1;
		
		if(rhs.head != null){
			for(int i = 0; i < rhs.size(); i++){
				//pushBack(rhs.getAt(i));
				Node<T> temp2 = new Node<T>();
				temp2.value = rhs.getAt(i);
				if(head == null){
					head = temp2;
				}
				else{
					temp1 = head;
					for(int j = 1; j < size(); j++){
						temp1 = temp1.getNext();
					}
					temp1.setNext(temp2);
				}
			}
		}
		else{head = null;}
	}
	//Constructor - Extra Implementation. Used in acquiring the words5.dict and putting it in a list at a much faster rate.
	SimpleList(T[] array){
		Node<T> temp;
		Node<T> newNode = new Node<T>();
		
		//add first element and start list
		newNode.value = array[0];
		head = newNode;
		temp = head;
		
		int i = 1;
		while(array[i] != null){
			newNode = new Node<T>();
			newNode.value = array[i];
			
			//System.out.println(newNode.value);
			
			temp.next = newNode;
			temp = temp.next;
			i++;
		}
		
	}
	//MyList Methods
	//Returns the previous node for the specified node curr.
	Node<T> previous(Node<T> curr){
		Node<T> temp = null;
		
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
	Node<T> next(Node<T> curr){
		return curr.getNext();
	}
	//Returns the element at the specified position in this list. Index of first element in list is 0.
	T getAt(int index){
		Node<T> temp = null;
		
		if(head != null){
			temp = head;
			for(int i = 0; i < index; i++){
				temp = temp.next;
			}
		}
		return temp.getElement();
	}
	//Replaces the element at the specified position in this list with the specified element.
	void setAt(int index, T value){
		Node<T> temp;
		
		if(head != null){
			temp = head;
			for(int i = 0; i < index; i++){
				temp = temp.next;
			}
			temp.setElement(value);
		}
	}
	//Inserts a node with specified value at position i in the list, shifting elements starting at i to the right, if needed.
	void insertAtPos(int index, T value){
		Node<T> temp; //temporary reference to aid in adding new node
		Node<T> newNode = new Node<T>(); //Create new Node
		
		
		//Add to beginning of list
		if(index == 0){
			newNode.setElement(value);
			//pushFront(value);
			if(head == null){
				head = newNode;
			}
			else{
				newNode.setNext(head);
				head = newNode;	
			}
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
			//pushBack(value);
			newNode.setElement(value);
			
			if(head == null){
				head = newNode;
			}
			else{
				temp = head;
				for(int i = 1; i < size(); i++){
					temp = temp.getNext();
				}
				temp.setNext(newNode);
			}
		}
		else if(index < 0 || index > size()){
			System.out.println("Outside of index range");
		}
	}
	//Removes the element at the specified position in this list. Returns true if this list contained the specified element.
	boolean removeAt(int index){
		Node<T> temp = null;
		
		//Remove last element
		if(index == 0){
			//popFront();
			if(head == null){
				System.out.println("List is empty.");
			}
			else{
				head = head.next;	
			}
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
			//popBack();
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
			return true;
		}
		else if(index < 0 || index >= size()){
			System.out.println("Outside of index range");
		}
		
		return false;
	}
	//Returns the number of items in the list.
	int size(){
		int size = 0;
		Node<T> temp = null;
		
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
				System.out.print(""+getAt(i)+" ");
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
			str = ""+str+getAt(i);
		}
		return str;
	}
}
