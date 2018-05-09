import java.io.FileReader;
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
 * Assignment: Lab 6
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
		HashTable hashtable1, hashtable2, hashtable3, hashtable4;
		
		
		if(args.length < 1 || args.length > 1){
			System.out.println("Exectue using the following format");
			System.out.println("java Main input_file");
		}
		else if(args.length == 1){
			hashtable1 = new HashTable(args[0], 1);
			hashtable1.print();
			hashtable1.printStats();
			System.out.println();
			
			hashtable2 = new HashTable(args[0], 2);
			hashtable2.print();
			hashtable2.printStats();
			System.out.println();

			hashtable3 = new HashTable(args[0], 3);
			hashtable3.print();
			hashtable3.printStats();
			System.out.println();

			hashtable4 = new HashTable(args[0], 4);
			hashtable4.print();
			hashtable4.printStats();
		}
	}

}
