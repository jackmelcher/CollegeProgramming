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
 * Filename : MyQueue.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
public class MyQueue<T> {
	//MyQueue Fields
	SimpleList<T> list;
	
	//MyQueue Constructors
	public MyQueue(){
		list = new SimpleList<T>();
		
	}
	
	//MyQueue Methods
	//Returns true if queue is empty
	public boolean isEmpty(){
		if(list.size() == 0){
			return true;
		}
		else{
			return false;
		}
	}
	//Inserts value onto the rear of the queue.
	public void push(T value){
		list.insertAtPos(list.size(), value);
	}
	//Removes the queue's front item. Throws a QueueUnderflowException if the queue is empty. This exception should be handled within this method.
	public void pop(){
		try{
			if(isEmpty()){
				String message = "pop() on MyStack of size == "+list.size();
				throw new QueueUnderflowException(message);
			}
			list.removeAt(0);
		}
		catch(QueueUnderflowException e){
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
	}
	//Returns the front item in the queue. Throws a QueueUnderflowException if the queue is empty. This exception should be handled within this method.
	public T front(){
		T value = null;
		try{
			if(isEmpty()){
				String message = "front() on MyStack of size == "+list.size();
				throw new QueueUnderflowException(message);
			}
			value = list.getAt(0);
		}
		catch(QueueUnderflowException e){
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
		return value;
	}
}
