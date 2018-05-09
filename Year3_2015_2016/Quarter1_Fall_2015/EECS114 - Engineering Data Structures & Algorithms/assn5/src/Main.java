/**
 * Course: EECS 114 Fall 2015
 *
 * First Name: Jack
 * Last Name: Melcher
 * Lab Section: 1A
 * email address: jmelcher@uci.edu
 *
 *
 * Assignment: Assignment 5
 * Filename : Main.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
public class Main {
	public static void main(String[] args) {
		
		Jug die_hard = new Jug(3, 5, 4, 1, 1, 1, 1, 1, 1);
		die_hard.Solve();
		
		die_hard = new Jug(3,5,4,1,2,3,4,5,6);
		die_hard.Solve();
		
		
	}
}
