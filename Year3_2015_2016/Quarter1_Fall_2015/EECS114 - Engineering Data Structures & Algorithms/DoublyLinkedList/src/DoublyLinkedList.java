import java.util.Collection;

/**
 * Course: EECS 114 Fall 2015
 *
 * First Name: Jack
 * Last Name: Melcher
 * Lab Section: 1A
 * email address: jmelcher@uci.edu
 *
 *
 * Assignment: Lab2
 * Filename : DoublyLinkedList.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

public class DoublyLinkedList<T> {
	//fields
	private int numberOfNodes;
	private Node<T> head;
	private Node<T> tail;
	
	private class Node<T> {
		//TODO: add fields here
		public T type;
		public Node<T> next;
		public Node<T> prev;
		
		//Node Constructors
		Node (){
			this.type = null;
			this. next = null;
			this. prev = null;
		}
		Node (T type){
			this.type = type;
			this. next = null;
			this. prev = null;
		}
	}
	
	//DoublyLinkedList Constructors
	public DoublyLinkedList () {
		this.numberOfNodes = 0;
		this.head = null;
		this.tail = null;
	}
	public <E> DoublyLinkedList (Collection<? extends E> c) {
		//Did not want to do
	}

	public void add(int index, T t){
		Node<T> temp; //temporary reference to aid in adding new node
		Node<T> newNode = new Node<T>(t); //Create new Node
		
		//Add to an empty list
		if(index == 0 && isEmpty()){
			head = newNode;
			tail = newNode;
			
			numberOfNodes++;
		}
		//Add to beginning of list
		else if(index == 0 && !isEmpty()){
			head.prev = newNode;
			newNode.next = head;
			head = newNode;
			
			numberOfNodes++;
		}
		//Add at index of list
		else if(index > 0 && index < size()){
			temp = head;
			for(int i = 0; i < index-1; i++){
				temp = temp.next;
			}
			newNode.next = temp.next;
			temp.next = newNode;
			newNode.prev = temp;
			newNode.next.prev = newNode;
			
			numberOfNodes++;
		}
		//Add to end of list
		else if(index == size()){
			tail.next = newNode;
			newNode.prev = tail;
			tail = newNode;
			
			numberOfNodes++;
		}
		else{System.out.println("Cannot Add. Index outside of list bounds");}

	}
	
	public void remove(int index) {
		Node<T> temp; //temporary reference to aid in removing node

		if(!isEmpty()){
			//Remove last element
			if(index == 0 && size()== 1){
				head = null;
				tail = null;
				
				numberOfNodes--;
			}
			//Remove from beginning of list
			else if(index == 0){
				head = head.next;
				head.prev.next = null;
				head.prev = null;
				
				numberOfNodes--;
			}
			//Remove at index of list
			else if(index > 0 && index < size()-1){
				temp = head;
				for(int i = 0; i < index; i++){
					temp = temp.next;
				}
				temp.prev.next = temp.next;
				temp.next.prev = temp.prev;
				temp.prev = null;
				temp.next = null;
				
				numberOfNodes--;
			}
			//Remove from end of list
			else if(index == size()-1){
				tail = tail.prev;
				tail.next.prev = null;
				tail.next = null;
				
				numberOfNodes--;
			}
			else{System.out.println("Cannot Remove. Index outside of list bounds");}
		}
		else{System.out.println("Cannot Remove. List is empty");}

	}
	
	public void remove(Object o) {
		Node<T> temp; //temporary reference to aid in removing node
		temp = head;
		int j = 0;
		int originalsize = size();
		if(!isEmpty()){
			for(int i = 0; i < size(); i++){
				//First occurrence of type found
				if(temp.type.equals(o)){
					//Remove last element
					if(i == 0 && size() == 1){
						head = null;
						tail = null;
						
						numberOfNodes--;
					}
					//Remove from beginning of list
					else if(i == 0){
						head = head.next;
						head.prev.next = null;
						head.prev = null;
						
						numberOfNodes--;
					}
					//Removing in middle of list
					else if(i > 0 && i < size()-1){
						temp.prev.next = temp.next;
						temp.next.prev = temp.prev;
						temp.prev = null;
						temp.next = null;
						
						numberOfNodes--;
					}
					//Remove from end of list
					else if(i == size()-1){
						tail = tail.prev;
						tail.next.prev = null;
						tail.next = null;
						
						numberOfNodes--;
					}
					
					break;
				}
				else{temp = temp.next; j++;}
			}
		}
		else{System.out.println("Cannot Remove. List is empty");}
		if(j == originalsize){System.out.println("Cannot Remove. Object not found");}
	}

	/**
	  *  Returns the element at the specified position.
	  *  
	  * @param index the position in which to look for.
	  * @return the element at the given position in the list. If the index is out of range (index < 0 || index >=size())
	  */
	public T get(int index) {
		Node<T> temp; //temporary reference to aid in getting T
		temp = head;
		if(index == 0 && !isEmpty()){
			return head.type;
		}
		else if(index > 0 && index < size()-1){
			for(int i = 0; i < index; i++){
				temp = temp.next;
			}
			return temp.type;
		}
		else if(index == size()-1){
			return tail.type;
		}
		else {
			System.out.println("Index outside of list bounds");
			return null;
		}
	}
	
	public int size() {return numberOfNodes;}
	
	public boolean isEmpty() {
		if(numberOfNodes == 0){return true;}
		else{return false;}
	}

}
