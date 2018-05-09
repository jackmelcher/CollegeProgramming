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
 * Filename : MyStack.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
public class MyStack<T> {
	//MyStack Fields
	private final int CAPACITY = 1000;//size of the stack's internal array
	private int top;//index to the position of the top item in the stack
	private T[] data;//array that holds contents of the stack
	
	//MyStack Constructors
	//Constructor. Initializes and allocates an empty stack.
	@SuppressWarnings("unchecked")
	MyStack(){
		top = -1;
		data = (T[])new Object[CAPACITY];
	}
	
	//MyStack Methods
	//Returns true if stack is empty.
	public boolean isEmpty () {
		if(top == -1){
			return true;
		}
		else{return false;}
	}
	//Returns the size of the stack.
	public int size(){
		return top+1;
	}
	//Inserts value onto the top of the stack. Throws a StackOverflowException if the stack is full. This exception should be handled within this method.
	public void push (T value) {
		try{
			if(top == CAPACITY-1){
				String message = "push() on MyStack with CAPACITY == "+CAPACITY+", size == "+size();
				throw new StackOverflowException(message);
			}
			top++;
			data[top] = value;
		}
		catch(StackOverflowException e){
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
		
	}
	//Removes the stack's top item. Throws a StackUnderException if the stack is empty. This exception should be handled within this method
	public void pop () {
		try{
			if(isEmpty()){
				String message = "pop() on MyStack of size == "+size();
				throw new StackUnderflowException(message);
			}
			data[top] = null;
			top--;
		}
		catch(StackUnderflowException e){
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
	}
	//Returns the stack's top item. Throws a StackUnderException if the stack is empty. This exception should be handled within this method.
	public T top () {
		T value = null;
		try{
			if(isEmpty()){
				String message = "top() on MyStack of size == "+size();
				throw new StackUnderflowException(message);
			}
			value = data[top];
		}
		catch(StackUnderflowException e){
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
		return value;
	}
}
