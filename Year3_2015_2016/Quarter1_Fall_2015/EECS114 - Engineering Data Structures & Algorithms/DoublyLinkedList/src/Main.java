import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
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
 * Assignment: Lab2
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
		//TODO: Input a file name from args[0] (it can be have a directory appended to it) and open file to store in Scanner object.
		if(args.length < 1){
			DoublyLinkedList<Integer> numLinkedList = new DoublyLinkedList<Integer>();
			
			System.out.println("New list created for Integer");
			System.out.println("isEmpty = " +numLinkedList.isEmpty());
			System.out.println("numberOfNodes = " +numLinkedList.size());
			
			System.out.println("Adding to list by index");
			//After the next three insertion, the list will be 6, 5, and 1 in this order.
			numLinkedList.add(0, 1); //1
			printList(numLinkedList);
			numLinkedList.add(0, 5); //51
			printList(numLinkedList);
			numLinkedList.add(0, 6); //651
			printList(numLinkedList);
	
			numLinkedList.add(2, 3); //6531
			printList(numLinkedList);
			numLinkedList.add(1, 7); //67531
			printList(numLinkedList);
			numLinkedList.add(numLinkedList.size(), 8);//675318
			printList(numLinkedList);
			numLinkedList.add(numLinkedList.size(), 9);//6753189
			numLinkedList.add(9, 2); //print error
			printList(numLinkedList);
			System.out.println("isEmpty = " +numLinkedList.isEmpty());
			System.out.println("numberOfNodes = " +numLinkedList.size());
	
			
			System.out.println("Removing from list by index");
			numLinkedList.remove(0); //753189
			printList(numLinkedList);
			numLinkedList.remove(3); //75389
			printList(numLinkedList);
			numLinkedList.remove(numLinkedList.size()-1); //7538
			numLinkedList.remove(numLinkedList.size()); //print error
			printList(numLinkedList);
	
			System.out.println("isEmpty = " +numLinkedList.isEmpty());
			System.out.println("numberOfNodes = " +numLinkedList.size());
			
			System.out.println("Removing from list by object");
			numLinkedList.remove(new Integer(7)); //538
			printList(numLinkedList);
			numLinkedList.remove(new Integer(3)); //58
			printList(numLinkedList);
			numLinkedList.remove(new Integer(8)); //5
			printList(numLinkedList);
			numLinkedList.remove(new Integer(1)); //print error
	
			numLinkedList.remove(0); //empty list
			System.out.println("List is now empty");
			System.out.println("isEmpty = " +numLinkedList.isEmpty());
			System.out.println("numberOfNodes = " +numLinkedList.size());

		}
		
		
		//TODO: Add more test cases for DoublyLinkedList, which should contain number elements inputted from Scanner object. Include test case for String. 
	    if(args.length >= 1){
			
			Scanner s = new Scanner(new BufferedReader(new FileReader(args[0]))).useDelimiter(",|\n");
			
			if(s.hasNextInt()){
		    	DoublyLinkedList<Integer> numLinkedList1 = new DoublyLinkedList<Integer>();
				System.out.println("New list created for Integer");
				System.out.println("isEmpty = " +numLinkedList1.isEmpty());
				System.out.println("numberOfNodes = " +numLinkedList1.size());
				
		        while(s.hasNextLine()){
		            int number = s.nextInt();
		            numLinkedList1.add(numLinkedList1.size(), number);
		            //System.out.println("" + number);
		    		printList(numLinkedList1);
		        }
				System.out.println("isEmpty = " +numLinkedList1.isEmpty());
				System.out.println("numberOfNodes = " +numLinkedList1.size());
			}

	        
			if(s.hasNext()){
				DoublyLinkedList<String> numLinkedList2 = new DoublyLinkedList<String>();
				System.out.println("New list created for String");
				System.out.println("isEmpty = " +numLinkedList2.isEmpty());
				System.out.println("numberOfNodes = " +numLinkedList2.size());
		
		        //Reading each line of file using Scanner class
		        while (s.hasNext()) {
		            String string = s.next();
		            numLinkedList2.add(numLinkedList2.size(), string);
		            System.out.println(""+string);
		        	//System.out.println(scnr1.next());
		        }
				System.out.println("isEmpty = " +numLinkedList2.isEmpty());
				System.out.println("numberOfNodes = " +numLinkedList2.size());
			}
			
	        s.close();

			/*     OLD CODE FOR REFERENCE
			File text = new File("numbers.txt");
		    Scanner scnr = new Scanner(text).useDelimiter(",");
	        //Reading each line of file using Scanner class
	        while(scnr.hasNextLine()){
	            int number = scnr.nextInt();
	            numLinkedList1.add(numLinkedList1.size(), number);
	            //System.out.println("" + number);
	    		printList(numLinkedList1);
	        }
	        scnr.close();
	        */
	        
			/*
			File text1 = new File("words5.dict");
	        Scanner scnr1 = new Scanner(text1);  
	        //Reading each line of file using Scanner class
	        while (scnr1.hasNext()) {
	            String string = scnr1.next();
	            numLinkedList2.add(numLinkedList2.size(), string);
	            System.out.println(""+string);
	        	//System.out.println(scnr1.next());
	        }
		    scnr1.close();
		    */
	    }
	}
	
	//Print list
	public static void printList(DoublyLinkedList list){
		for(int i = 0; i < list.size(); i++){
			System.out.print("" +list.get(i) +" ");
		}
		System.out.print("\n");
	}

}
