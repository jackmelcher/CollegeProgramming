import java.io.BufferedReader;
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
 * Assignment: Assignment 2
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
		// TODO Auto-generated method stub
	    SimpleList<String> words;
		WordLadder wordLadder;
		String startWord;
		String endWord;
		
	    if(args.length < 3 || args.length > 3){
			System.out.println("Exectue using the following format");
			System.out.println("java Main input_file start_word end_word");

	    }
	    else if(args.length == 3){
			
			Scanner s = new Scanner(new BufferedReader(new FileReader(args[0]))).useDelimiter(",|\n");
			
			startWord = args[1];
			endWord = args[2];

			
			String[] stringArray = new String[5000];
			int i = 0;
			String string = null;
			
			if(s.hasNext()){
				//Reading each line of file using Scanner class
		        while (s.hasNext()) {
		            string = s.next();
		            stringArray[i] = string;
		            //System.out.println(stringArray[i]);
		            i++;
		        }
		        
			}			
	        s.close();
          
	        words = new SimpleList<String>(stringArray);
			//System.out.println("numberOfNodes = " +words.size());

	        //Test cases
	        //wordLadder = new WordLadder(words, "style", "crazy");
	        //wordLadder = new WordLadder(words, "brave", "heart");
	        //wordLadder = new WordLadder(words, "stack", "steak");

	        wordLadder = new WordLadder(words, startWord, endWord);
		}
	}
}
