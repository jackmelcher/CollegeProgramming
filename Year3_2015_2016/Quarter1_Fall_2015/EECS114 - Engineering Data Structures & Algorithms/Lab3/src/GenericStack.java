import java.lang.reflect.Array;

/**
 * Course: EECS 114 Fall 2015
 *
 * First Name: Jack
 * Last Name: Melcher
 * Lab Section: 1A
 * email address: jmelcher@uci.edu
 *
 *
 * Assignment: Lab 3
 * Filename : GenericStack.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

public class GenericStack<T> {
	//Fields
	private Object[] stack;
	private int top; // top index in array
	public static final int CAPACITY = 1000;
	
	//Constructors
	public GenericStack () {
		top = -1;
		stack = (T[])new Object[CAPACITY];
	}	
	//Methods
	//Adds a new element x at the top of the stack.
	public void push (T x) {
		if(top < CAPACITY-1){
			top++;
			stack[top] = x;
			//System.out.println("top = "+top);
		}
		else{System.out.println("Stack is full");}
	}
	//Returns a reference to the next(top) element in the stack, if the stack is not already empty.
	public T top () {
		if (isEmpty()){
			System.out.println("Stack is empty");
			return null;
		}
		else{return (T) stack[top];}
	}
	//Removes the element on top of the stack, reducing the stack's size by 1 if the stack is not already empty.
	public void pop () {
		if(!isEmpty()){
			stack[top] = 0;
			top--;
			//System.out.println("top = "+top);
		}
		else{System.out.println("Stack is empty");}
	}
	//Tests whether the stack size is zero. Primarily used to ensure that a pop() or top() operation is not performed on an empty instance of a Stack. Returns true if stack is empty, false otherwise.
	public boolean isEmpty () {
		if(top == -1){
			return true;
		}
		else{return false;}
	}
}
