/**
 * Course: EECS 114 Fall 2015
 *
 * First Name: Jack
 * Last Name: Melcher
 * Lab Section: 1A
 * email address: jmelcher@uci.edu
 *
 *
 * Assignment: Lab 7
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
		//Perform all testing of BST within main method. 
		//Example Insertion Sequence: 4 2 6 1 3 5 7 (Balanced BST)
		
		BST bst = new BST();
		
		System.out.println("Insert tests");
		bst.insert(4);
		bst.insert(2);
		bst.insert(6);
		bst.insert(1);
		bst.insert(3);
		bst.insert(5);
		bst.insert(7);
		
		bst.display();
		System.out.println();

		bst.inorder();
		System.out.println();

		bst.postorder();
		System.out.println();

		bst.preorder();
		System.out.println();
		
		bst.displayInorderPos();
		System.out.println();

		bst.displayDepth();
		System.out.println();

		bst.displayHeight();
		System.out.println();
		
		System.out.println("Remove tests");

		bst.remove(7);
		bst.display();
		System.out.println();
		bst.remove(1);
		bst.display();
		System.out.println();
		bst.remove(1);
		bst.display();
		
		System.out.println();
		bst.remove(4);
		bst.display();
		
		bst.inorder();
		System.out.println();

		bst.postorder();
		System.out.println();

		bst.preorder();
		System.out.println();
		
		bst.displayInorderPos();
		System.out.println();

		bst.displayDepth();
		System.out.println();

		bst.displayHeight();
		System.out.println();
		
		bst = new BST();
		bst.insert(4);
		bst.display();
		bst.remove(4);
		bst.display();


	}

}
