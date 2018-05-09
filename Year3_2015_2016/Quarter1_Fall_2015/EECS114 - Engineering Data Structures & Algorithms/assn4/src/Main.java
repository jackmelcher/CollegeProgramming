import java.io.File;
import java.io.FileNotFoundException;
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
 * Assignment: Assignment 4
 * Filename : Main.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
public class Main {

	public static void main(String[] args) throws FileNotFoundException{
		
		int[] test1 = {10,7,14,9,8,6,12,2,19};
		int[] test2 = {1,14,13,16,23,19,17};
		PriorityQueue pq = new PriorityQueue();

		pq.push(2,5);
		pq.push(1,4);
		pq.push(5,8);
		pq.push(3,2);
		pq.push(4,7);
		pq.push(5,5);
		pq.print();
		
		pq.push(4,3);//decrease key
		pq.print();
		
		pq.push(1,1);
		pq.push(4,10);//increase key
		pq.print();
	}

}
