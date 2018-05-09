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
 * Filename : BST.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

public class BST {

	private static class BinaryNode{
		//BinaryNode Fields
		int value;
		BinaryNode left;
		BinaryNode right;
		
		//Three additional fields
		//the height of the BinaryNode
		private int height;
		//the depth of the BinaryNode
		private int depth;
		//the position of a given node in a sorted order (determined by inorder traversal)
		private int inorder_pos;
		
		//BinaryNode Constructor
		public BinaryNode(int newVal){
			this.value = newVal;
		}
		
		
		//BinaryNode Methods
		
		//Inserts a new node with specified value in the BST tree with t as its root.
		//The BST tree pointed to by t must still maintain the BST property for every node after insertion.
		//This tree should remain the same if it has given value already.
		private static BinaryNode insert(int value, BinaryNode t){
			BinaryNode newNode = new BinaryNode(value);
			
			BinaryNode temp1, temp2;
			temp1 = t;
			temp2 = null;
						
			while(temp1 != null){
				temp2 = temp1;
				
				if(newNode.value < temp1.value){
					temp1 = temp1.left;
				}
				else{
					temp1 = temp1.right;
				}
			}
			
			if(temp2 == null){
				t = newNode;
			}
			else if(newNode.value < temp2.value){
				temp2.left = newNode;
			}
			else{
				temp2.right = newNode;
			}
			
			return t;
		}
		
		//Removes a node with specified value in the BST tree with t as its root.
		//The BST tree pointed to by t must still maintain the BST property for every node after removal. 
		//This tree should remain the same if it does not have the given value.
		//The remove method must implement remove from Lecture slides 7.
		private static BinaryNode remove(int value, BinaryNode t){
			BinaryNode temp1, temp2;
			temp1 = t;
			temp2 = null;
			
			while(temp1 != null && temp1.value != value){
				temp2 = temp1;

				//traverse otherwise
				if(value < temp1.value){
					temp1 = temp1.left;
				}
				else{
					temp1 = temp1.right;
				}
				
			}
			//removal
			if(temp1 != null && value == temp1.value){
				//if the node has a left child
				if(temp1.left != null){
					temp1.value = findMax(temp1);
				}
				//if node has a right child
				else if(temp1.right != null){
					temp1.value = findMin(temp1);
				}
				//else no children
				else{
					//when not the root
					if(temp1 != t){
						if(temp1.value < temp2.value){
						temp2.left = null;
						}
						else{
							temp2.right = null;
						}
					}
					//root of tree with no children
					else{
						t = null;
					}
					
				}
			}
			
			return t;
		}
		//Extra Removal methods
		private static int findMax(BinaryNode node){
			BinaryNode temp1, temp2;
		
			temp1 = node.left;
			temp2 = node;
			
			//Find maximum value
			while(temp1.right != null){
				temp2 = temp1;

				temp1 = temp1.right;				
			}
			
			//extra removal step
			//if the node has a left child
			if(temp1.left != null){
				temp1.value = findMax(temp1.left);
			}
			//if node has a right child
			else if(temp1.right != null){
				temp1.value = findMin(temp1.right);
			}
			//else no children
			else{
				if(temp1.value < temp2.value){
					temp2.left = null;
				}
				else{
					temp2.right = null;
				}
			}
			
			return temp1.value;
		}
		private static int findMin(BinaryNode node){
			BinaryNode temp1, temp2;
			
			temp1 = node.right;
			temp2 = node;
			
			//Find minimum value
			while(temp1.left != null){
				temp2 = temp1;

				temp1 = temp1.left;				
			}
			
			//extra removal step
			//if the node has a left child
			if(temp1.left != null){
				temp1.value = findMax(temp1.left);
			}
			//if node has a right child
			else if(temp1.right != null){
				temp1.value = findMin(temp1.right);
			}
			//else no children
			else{
				if(temp1.value < temp2.value){
					temp2.left = null;
				}
				else{
					temp2.right = null;
				}
			}
			
			return temp1.value;
		}

		//Prints the BST in reverse inorder traversal with indentation of one space per level.
		//It must only show the contents of BST tree as shown in the example below (Note that the example tree is rotated by 90 degrees yet readable).
		/*Example: After inserting 4 2 6 1 3 5 7 in order, display() should only print out the following to standard output:
     		 7 
		    6 
		     5 
		   4 
		     3 
		    2 
		     1 
		 */
		private static void display(BinaryNode t){
			if(t != null){
				display(t.right);
				for(int i = 0; i < t.depth; i++){
					System.out.print(" ");
				}
				System.out.println(t.value);
				display(t.left);
			}
		}
		
		//Additional methods
		//Add three methods to traverse
		private static void inorder(BinaryNode t){
			if(t != null){
				inorder(t.left);
				System.out.println(t.value);
				inorder(t.right);
			}
		}
		private static void postorder(BinaryNode t){
			if(t != null){
				postorder(t.left);
				postorder(t.right);
				System.out.println(t.value);
			}
		}
		private static void preorder(BinaryNode t){
			if(t != null){
				System.out.println(t.value);
				preorder(t.left);
				preorder(t.right);
			}
		}
		//Add three methods that traverse the BST and update each BinaryNode's height, depth, and inorder position.
		private static void updateHeight(BinaryNode t){
			if(t != null){
				if(curr_height > 0){
					curr_height--;
				}
				updateHeight(t.left);
				updateHeight(t.right);
				
				t.height = curr_height;
				curr_height++;
			}
		}
		private static void updateDepth(BinaryNode t){
			if(t != null){
				t.depth = curr_depth;
				curr_depth++;
				updateDepth(t.left);
				updateDepth(t.right);
				if(curr_depth > 0){
					curr_depth--;
				}
			}
		}
		private static void updateInorderPos(BinaryNode t){
			if(t != null){
				updateInorderPos(t.left);
				curr_inorder_pos++;
				t.inorder_pos = curr_inorder_pos;
				updateInorderPos(t.right);
			}
		}
		//Add three methods that display a BinaryNode's key and height, key and depth, key and inorder position.
		private static void displayHeight(BinaryNode t){
			if(t != null){
				System.out.println("BinaryNode's key: "+t.value+",height: "+t.height);
				displayHeight(t.left);
				displayHeight(t.right);
			}
		}
		private static void displayDepth(BinaryNode t){
			if(t != null){
				System.out.println("BinaryNode's key: "+t.value+",depth: "+t.depth);
				displayDepth(t.left);
				displayDepth(t.right);
			}
		}
		private static void displayInorderPos(BinaryNode t){
			if(t != null){
				displayInorderPos(t.left);
				System.out.println("BinaryNode's key: "+t.value+",inorder_pos: "+t.inorder_pos);
				displayInorderPos(t.right);
			}
		}
	}
	
	//BST Fields
	private static int curr_depth = 0;
	private BinaryNode root = null;
	
	//Additional fields
	private static int curr_height = 0;
	private static int curr_inorder_pos = 0;

	//BST Methods
	
	//Calls BinaryNode.insert(value, root) (see code for insert(int value, BinaryNode t) in BinaryNode class)
	public void insert(int value){
		root = BinaryNode.insert(value, root);
		updateHeight();
		updateDepth();
		updateInorderPos();
	}
	
	//Calls BinaryNode.remove(value, root) (see code for remove(int value, BinaryNode t) in BinaryNode class)
	public void remove(int value){
		root = BinaryNode.remove(value, root);
    	updateHeight();
    	updateDepth();
	    updateInorderPos();
	}
	
	//Calls BinaryNode.display(root) (see code for display(BinaryNode t) in BinaryNode class)
	public void display(){
		if(root != null){
			BinaryNode.display(root);
		}
		else{System.out.println("BST is empty");}
	}
	
	//Additional Methods
	//Add three methods to traverse
	public void inorder(){
		System.out.println("BST inorder");
		if(root != null){
			BinaryNode.inorder(root);
		}
		else{System.out.println("BST is empty");}
	}
	public void postorder(){
		System.out.println("BST postorder");
		if(root != null){
			BinaryNode.postorder(root);
		}
		else{System.out.println("BST is empty");}
	}
	public void preorder(){
		System.out.println("BST preorder");
		if(root != null){
			BinaryNode.preorder(root);
		}
		else{System.out.println("BST is empty");}
	}
	//Add three methods that traverse the BST and update each BinaryNode's height, depth, and inorder position.
	public void updateHeight(){
		if(root != null){
			BinaryNode.updateHeight(root);
		}
	}
	public void updateDepth(){
		if(root != null){
			BinaryNode.updateDepth(root);
		}
	}
	public void updateInorderPos(){
		curr_inorder_pos = 0;
		if(root != null){
			BinaryNode.updateInorderPos(root);
		}
	}
	//Add three methods that display a BinaryNode's key and height, key and depth, key and inorder position.
	public void displayHeight(){
		if(root != null){
			BinaryNode.displayHeight(root);
		}
		else{System.out.println("BST is empty");}
	}
	public void displayDepth(){
		if(root != null){
			BinaryNode.displayDepth(root);
		}
		else{System.out.println("BST is empty");}
	}
	public void displayInorderPos(){
		if(root != null){
			BinaryNode.displayInorderPos(root);
		}
		else{System.out.println("BST is empty");}
	}
}
