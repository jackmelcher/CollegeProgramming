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
 * Filename : StackUnderflowException.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
public class StackUnderflowException extends Exception{
	/**
	 * 
	 */
	private static final long serialVersionUID = 919964437065405320L;
	
	StackUnderflowException(){
		super();
	}
	StackUnderflowException(String s){
		super(s);
	}
}
