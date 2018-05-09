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
 * Filename : WordLadder.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
public class WordLadder {

	/*Algorithm Find Word Ladder
	
	create a stack of strings
	push the start word on this stack
	create a queue of stacks
	enqueue this stack
	
	while the queue is not empty
		for each word in the dictionary
			if a word is 1-letter different in any position than top string of the front stack
				if this word is the end word
					// Done! The front stack plus this word is your word ladder.
					output this word ladder
				make a copy of the front stack
				push the found word onto the copy
				enqueue the copy.
		dequeue front stack
	
	 */
	
	//WordLadder Fields
	String start;
	String end;
	SimpleList<String> words;
	MyStack<String> stack;
    MyQueue<MyStack<String>> queue;
    
	SimpleList<String> wordLadderList;
		 
	//WordLadder Constructor
	public WordLadder(SimpleList<String> words, String start, String end){
		this.words = words;
		this.start = start;
		this.end = end;
		int wordsSize = words.size();
		boolean wordLadderFound = false;
		
	    System.out.println("Beginning WordLadder");
	    System.out.println("Start word = "+start);
	    System.out.println("End word = "+end);

	    stack = new MyStack<String>();//create a stack of strings
	    stack.push(start);//push the start word on this stack
	    queue = new MyQueue<MyStack<String>>();//create a queue of stacks
	    queue.push(stack);//enqueue this stack
	    
	    String queueTempString;//used when comparing words
	    String wordsTempString;//used when comparing words
	    
	    MyStack<String> originalStack;//used when copying stack
	    MyStack<String> copyStack;//used when copying stack
	    SimpleList<String> copyList;//used when copying stack
	    	    
	    //while the queue is not empty
	    while(!queue.isEmpty()){	    	
	    	//for each word in the dictionary
		    for(int i = 0; i < wordsSize; i++){
	    		queueTempString = queue.front().top();
	    		wordsTempString = words.getAt(i);
	    		
	    		//System.out.println("Top word = "+queueTempString+"  Dict word = "+wordsTempString);
	    		
	    		//if a word is 1-letter different in any position than top string of the front stack
	    		if(allButOneLetter(queueTempString, wordsTempString)){
	    			//if this word is the end word
	    			if(wordsTempString.matches(end)){
	    				
	    	    	    System.out.println("WordLadderFound");
	    	    	    
	    				// Done! The front stack plus this word is your word ladder.
	    				queue.front().push(wordsTempString);
	    				//output this word ladder
	    				wordLadderList = new SimpleList<String>();  				
	    				while(!queue.front().isEmpty()){
		    				wordLadderList.insertAtPos(0, queue.front().top());
		    				queue.front().pop();
	    				}
	    				wordLadderList.print();
	    				System.out.println("numberOfNodes = " +wordLadderList.size());
	    				wordLadderFound = true;
	    				break;
	    			}
	    			//make a copy of the front stack
	    			originalStack = queue.front();//references original stack
	    			copyStack = new MyStack<String>();//will become copy of original stack
	    			copyList = new SimpleList<String>();//aids in copying
    				//pops original stack and puts words into copyList
	    			while(!originalStack.isEmpty()){
    					copyList.insertAtPos(0, queue.front().top());
	    				queue.front().pop();
    				}
	    			//pushes words back into originalStack
    				for(int j = 0; j < copyList.size(); j++){
    					originalStack.push(copyList.getAt(j));
    				}
	    			//pushes words into copyStack
    				for(int j = 0; j < copyList.size(); j++){
    					copyStack.push(copyList.getAt(j));
    				}
	    			//push the found word onto the copy
    				copyStack.push(wordsTempString);
					//enqueue the copy.
    				queue.push(copyStack);
    				
    				//remove the found word from dictionary
    				words.removeAt(i);
    				wordsSize--;
	    		}
	    	}	    
			//dequeue front stack
	    	queue.pop();
	    	
	    	if(wordLadderFound){
	    		break;
	    	}
	    }
	    if(!wordLadderFound){
    		System.out.println("WordLadder could not be found.");
    	}
	}
	
    //WordLadder Methods
	public boolean allButOneLetter(String str1, String str2){
		if (str1.length() != str2.length())
	        return false;
	    
		int same = 0;
	    for (int i = 0; i < str1.length(); ++i) {
	        if (str1.charAt(i) == str2.charAt(i))
	            same++;
	    }
		
	    /*
	    if(same == str1.length() - 1){
	    	System.out.println("String with one letter difference found");
	    }*/
	    
	    return same == str1.length() - 1;				
	}

}
