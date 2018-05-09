import java.util.Random;

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
 * Filename : OpenAddressCollisionTests.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

public class OpenAddressCollisionTests {
	
	public static final int Capacity = 1009;
	//public static int NumberOfIntegers = 908;
	public static final int MaximumInteger = 100;
	public static final int MaximumOffset = 1000000;
	
	public static int[] hashtable1 = new int[Capacity];
	public static int[] hashtable2 = new int[Capacity];
	public static int[] hashtable3 = new int[Capacity];

	public static int linearCollisions = 0;
	public static int quadraticCollisions = 0;
	public static int cubicCollisions = 0;
	
	public static void linearProbing(int key){
		int index =0;
		for(int i = 0; i < MaximumOffset; i++){
			index = (key % Capacity + i) % Capacity;
			//System.out.println(index);
			if(hashtable1[index] == 0){
				hashtable1[index] = key;
				break;
			}
			else{
				//System.out.println("Collision Occurred");
				linearCollisions++;
			}
		}
	}
	
	public static void quadraticProbing(int key){
		int index =0;
		for(int i = 0; i < MaximumOffset; i++){
			index = (int) ((key % Capacity + Math.pow(i, 2))%Capacity);
			if(hashtable2[index] == 0){
				hashtable2[index] = key;
				break;
			}
			else{quadraticCollisions++;}
		}
	}
	
	public static void cubicProbing(int key){
		int index =0;
		for(int i = 0; i < MaximumOffset; i++){
			index = (int) ((key % Capacity + Math.pow(i, 3))%Capacity);
			if(hashtable3[index] == 0){
				hashtable3[index] = key;
				break;
			}
			else{cubicCollisions++;}
		}
	}
	
	public static void main(String[] args) {

		Random rand = new Random();
		int randomInteger = 0;
		int NumberOfIntegers = 0; 
		
		//25% Capacity
		hashtable1 = new int[Capacity];
		hashtable2 = new int[Capacity];
		hashtable3 = new int[Capacity];
		linearCollisions = 0;
		quadraticCollisions = 0;
		cubicCollisions = 0;
		NumberOfIntegers = (int) (Capacity*0.25);
		for(int i = 0; i < NumberOfIntegers; i++){
			randomInteger = rand.nextInt(MaximumInteger)+1;
			//System.out.println(randomInteger);
			
			//Linear Probing
			linearProbing(randomInteger);
			//Quadratic Probing
			quadraticProbing(randomInteger);
			//Cubic Probing
			cubicProbing(randomInteger);
		}
		System.out.println("Open Addressing at 25% Capacity");
		System.out.println("Number of Linear Probing Collisions: "+linearCollisions);
		System.out.println("Number of Quadratic Probing Collisions: "+quadraticCollisions);
		System.out.println("Number of Cubic Probing Collisions: "+cubicCollisions);
		System.out.println();
		
		//50% Capacity
		hashtable1 = new int[Capacity];
		hashtable2 = new int[Capacity];
		hashtable3 = new int[Capacity];
		linearCollisions = 0;
		quadraticCollisions = 0;
		cubicCollisions = 0;
		NumberOfIntegers = (int) (Capacity*0.50);
		for(int i = 0; i < NumberOfIntegers; i++){
			randomInteger = rand.nextInt(MaximumInteger)+1;
			//System.out.println(randomInteger);
			
			//Linear Probing
			linearProbing(randomInteger);
			//Quadratic Probing
			quadraticProbing(randomInteger);
			//Cubic Probing
			cubicProbing(randomInteger);
		}
		System.out.println("Open Addressing at 50% Capacity");
		System.out.println("Number of Linear Probing Collisions: "+linearCollisions);
		System.out.println("Number of Quadratic Probing Collisions: "+quadraticCollisions);
		System.out.println("Number of Cubic Probing Collisions: "+cubicCollisions);
		System.out.println();

		//75% Capacity
		hashtable1 = new int[Capacity];
		hashtable2 = new int[Capacity];
		hashtable3 = new int[Capacity];
		linearCollisions = 0;
		quadraticCollisions = 0;
		cubicCollisions = 0;
		NumberOfIntegers = (int) (Capacity*0.75);
		for(int i = 0; i < NumberOfIntegers; i++){
			randomInteger = rand.nextInt(MaximumInteger)+1;
			//System.out.println(randomInteger);
			
			//Linear Probing
			linearProbing(randomInteger);
			//Quadratic Probing
			quadraticProbing(randomInteger);
			//Cubic Probing
			cubicProbing(randomInteger);
		}
		System.out.println("Open Addressing at 75% Capacity");
		System.out.println("Number of Linear Probing Collisions: "+linearCollisions);
		System.out.println("Number of Quadratic Probing Collisions: "+quadraticCollisions);
		System.out.println("Number of Cubic Probing Collisions: "+cubicCollisions);
		System.out.println();
		
		//90% Capacity
		hashtable1 = new int[Capacity];
		hashtable2 = new int[Capacity];
		hashtable3 = new int[Capacity];
		linearCollisions = 0;
		quadraticCollisions = 0;
		cubicCollisions = 0;
		NumberOfIntegers = (int) (Capacity*0.90);
		for(int i = 0; i < NumberOfIntegers; i++){
			randomInteger = rand.nextInt(MaximumInteger)+1;
			//System.out.println(randomInteger);
			
			//Linear Probing
			linearProbing(randomInteger);
			//Quadratic Probing
			quadraticProbing(randomInteger);
			//Cubic Probing
			cubicProbing(randomInteger);
		}
		System.out.println("Open Addressing at 90% Capacity");
		System.out.println("Number of Linear Probing Collisions: "+linearCollisions);
		System.out.println("Number of Quadratic Probing Collisions: "+quadraticCollisions);
		System.out.println("Number of Cubic Probing Collisions: "+cubicCollisions);
		System.out.println();
	}
}
