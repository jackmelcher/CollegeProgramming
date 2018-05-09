import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Random;
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
 * Assignment: Lab 3
 * Filename : Main.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
	    IntStack stack = new IntStack();
	    GenericStack<String> stack2 = new GenericStack<String>();
		
	    System.out.println("args.length = "+args.length);

		if (args.length < 1) {
			System.out.println(stack.top());
			stack.push(100);
			System.out.println(stack.top());
			stack.push(200);
			System.out.println(stack.top());
			stack.pop();
			System.out.println(stack.top());
			stack.pop();
			System.out.println(stack.top());
			stack.pop();
			System.out.println(stack.top());
			
			System.out.println(stack2.top());
			stack2.push("hello");
			System.out.println(stack2.top());
			stack2.push("world");
			System.out.println(stack2.top());
			stack2.pop();
			System.out.println(stack2.top());
			stack2.pop();
			System.out.println(stack2.top());

			
			System.out.print("Postfix Evaluation = ");
			RPNEval();
			//System.out.println("No input file provided. Expected Usage: java <executable> input.txt");
			System.exit(1);
		} 
		if(args.length >= 1){
			File text = new File(args[0]);
			try {
				Scanner inNums = new Scanner(text);
				if(inNums.hasNextInt()){
					while(inNums.hasNextInt()) {
						stack.push(inNums.nextInt());
						System.out.println(stack.top());
					}
				}
				else if(inNums.hasNext()){
					while(inNums.hasNext()) {
						stack2.push(inNums.next());
						System.out.println(stack2.top());
					}
				}
				inNums.close();
			} catch (FileNotFoundException e) {
				System.out.println(e.getMessage());
			}
		}
		stack.push(777777);
		System.out.println(stack.top());
		
		for(int i = 0; i < 1000; i++){
			stack.pop();
			System.out.println(stack.top());
		}

		
		
		System.exit(0);
	}
	
	public static void RPNEval () throws FileNotFoundException {
		File inputfile = new File("input.txt");
		Scanner postfixExpression = new Scanner(inputfile);
		
		GenericStack<Integer> stack = new GenericStack<Integer>();
		int temp_a, temp_b, temp_c= 0;
		String temp_string;
		char[] temp_char;
		
		while(postfixExpression.hasNext()){
			if(postfixExpression.hasNextInt()){
				stack.push(postfixExpression.nextInt());
			}
			// Occurs if first token of input is an operator, + or *, or anything else besides a number
			else if(stack.isEmpty()){
				System.out.println("Stack is empty");
				System.exit(1);
			}
			else{
				temp_b = stack.top();
				stack.pop();
				temp_string = postfixExpression.next();
				temp_char = temp_string.toCharArray();
				if(stack.isEmpty()){
					System.out.println("Stack is empty");
					System.exit(1);
				}
				else{
					temp_a = stack.top();
					stack.pop();
					switch(temp_char[0]){
					    case '+':
					        temp_c = temp_a + temp_b;
					        break;
					    case '-':
					        temp_c = temp_a - temp_b;
					        break;
					    case '*':
					        temp_c = temp_a * temp_b;
					        break;
					    case '/':
					        temp_c = temp_a / temp_b;
					        break;
					}
					stack.push(temp_c);
				}
			}
		}
		System.out.println(stack.top());

		
		postfixExpression.close();

	}
}
