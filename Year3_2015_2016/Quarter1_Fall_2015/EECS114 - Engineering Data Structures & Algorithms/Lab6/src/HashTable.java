import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;
import java.util.Vector;

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
 * Filename : HashTable.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

public class HashTable {
	//Fields
	//Set size of hash table to a prime number
	public static final int CAPACITY = 11;
	
	private Vector<Node> hashtable;
	private int numberOfCollisions = 0;
	
	private class Node {
		//TODO: add fields here
		public String element;
		public Node next;
		public Node prev;
		
		//Node Constructors
		Node (){
			this.element = null;
			this. next = null;
			this. prev = null;
		}
		Node (String element){
			this.element = element;
			this. next = null;
			this. prev = null;
		}
	}
	
	//Constructors
	//Create an empty hash table.
	public HashTable(){
		hashtable = new Vector<Node>(CAPACITY);
	}
	//Create a hash table from input file. 
	public HashTable(String filename, int hashFunction){
		hashtable = new Vector<Node>(CAPACITY);
		
		
		for(int i = 0; i < CAPACITY; i++){
			hashtable.add(i, null);
		}

		processFile(filename, hashFunction);
	}
	
	//Methods
	//This hash function adds up the ASCII values of the characters in the key.
	public int hashFunction1 (String key){
		char[] keyChars;
		int hashKey = 0;
		
		keyChars = key.toCharArray();
		for(int i = 0; i < keyChars.length; i++){
			hashKey += keyChars[i];
		}
		
		return hashKey % hashtable.capacity();
	}
	//This hash function uses the first three characters of the key, therefore all keys are assumed to be at least three 
	//characters long. The value for a key k is calculated as: k[0] + 27 * k[1] + 729 * k[2] where 27 represents the number 
	//of letters in the English alphabet, plus the blank, and 729 is 27^2.
	public int hashFunction2 (String key){
		char[] keyChars;
		int hashKey = 0;
		
		keyChars = key.toCharArray();
		hashKey = keyChars[0] + 27*keyChars[1] + 729*keyChars[2];
		
		return hashKey % hashtable.capacity();
	}
	
	//This hash function uses all characters in the key and calculates 
	//Summation from i=0,...,keysize-1 of k[keysize - i - 1] * 37^i. You can compute this polynomial function (of 37) by using Horner's rule, for example: 
	//h = k0 + (37 * k1) + (37^2 * k2) can be computed recursively by h = ( (k2) * 37 + k1 ) * 37 + k0.
	public int hashFunction3 (String key){
		char[] keyChars;
		int hashKey = 0;
		
		keyChars = key.toCharArray();
		for(int i = 0; i < keyChars.length; i++){
			hashKey += Math.pow(37, i)*keyChars[i];
		}
		
		return hashKey % hashtable.capacity();
	}
	
	//Hash function of personal choice.
	//Multiplies the first three characters in the string together
	public int hashFunction4 (String key){
		char[] keyChars;
		int hashKey = 0;
		
		keyChars = key.toCharArray();
		hashKey = keyChars[0] *keyChars[1] *keyChars[2];

		
		return hashKey % hashtable.capacity();
	}
	
	/*Print the hash table in the following format. Each array location will be printed on a separate line.
	 * The line will start with the number of the array location followed by a : and followed by one tab. 
	 * You will then print each word stored at that hash array location separated by a , and a single space.
	 * After all words at that hash array location are printed, you will output a return. 
	 * */
	public void print(){
		for(int i = 0; i < hashtable.size(); i++){
			//print index
			System.out.print(i+":\t");
			//print elements
			if(hashtable.get(i) != null){
				//print first element in chain
				System.out.print(hashtable.get(i).element+", ");
				
				Node temp = hashtable.get(i).next;
				while(temp != null){
					//print subsequent elements in chain
					System.out.print(temp.element+", ");
					temp = temp.next;
				}
			}
			System.out.println();
		}
	}
	
	//Add all of the words in the file specified as "filename" to the hash table.
	//Use push back to insert each of the words into the list at the hash location that the words hashes to.
	public void processFile(String filename, int hashFunction){
		String key;
		int index;
		Scanner s;
		
		try {
			s = new Scanner(new FileReader(filename));
			while (s.hasNext()) {
				key = s.next();
				//hash using specified hash function
				if(hashFunction == 1){
					index = hashFunction1(key);
				}
				else if(hashFunction == 2){
					index = hashFunction2(key);
				}
				else if(hashFunction == 3){
					index = hashFunction3(key);
							
				}
				else if(hashFunction == 4){
					index = hashFunction4(key);
				}
				else{//defaults to using hashFunction1 if not specified
					index = hashFunction1(key);
				}
				//insert key into hash table
				pushBack(key, index);
			}			
			s.close();
		} 
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	//Print the hash statistics: total number of collisions (keep track of this during insertions) the length of the longest list, and the average length of all lists.
	public void printStats(){
		//Total number of collisions
		System.out.println("Number of Collisions: "+numberOfCollisions);
		//Longest chain in the hash table
		int longestChain = 0;
		int numberInChain = 0;
		for(int i = 0; i < hashtable.size(); i++){
			numberInChain = 0;
			
			if(hashtable.get(i) != null){
				//count first element in chain
				numberInChain++;
				
				Node temp = hashtable.get(i).next;
				while(temp != null){
					//count subsequent elements in chain
					numberInChain++;
					temp = temp.next;
				}
			}
			if(numberInChain > longestChain){
				longestChain = numberInChain;
			}
		}
		System.out.println("Longest Chain Length: "+longestChain);

		//Average length of all chains in hash table.
		float averageChain = 0;
		float sum = 0;
		float numberOfChains = 0;
		
		for(int i = 0; i < hashtable.size(); i++){
			
			if(hashtable.get(i) != null){
				//count first element in chain
				numberOfChains++;
				sum++;
				
				Node temp = hashtable.get(i).next;
				while(temp != null){
					//count subsequent elements in chain
					sum++;
					temp = temp.next;
				}
			}
		}
		averageChain = sum/numberOfChains;
		System.out.println("Average Chain Length: "+averageChain);
	}
	
	//Inserts a node with specified value at the back of the chain.
	void pushBack(String key, int index){
		Node temp;
		
		Node newElement = new Node(key);
		
		temp = hashtable.get(index);
		
		if(temp == null){
			hashtable.set(index, newElement);
		}
		else if(temp != null){
			while(temp.next != null){
				temp = temp.next;
				numberOfCollisions++;
			}
			numberOfCollisions++;
			temp.next = newElement;
		}
		
	}
	
}
