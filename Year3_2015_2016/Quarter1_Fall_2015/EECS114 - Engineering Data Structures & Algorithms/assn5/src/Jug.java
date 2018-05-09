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
 * Assignment: Assignment 5
 * Filename : Jug.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
public class Jug {
	
	
	//Fields
	/*
	 * Ca = capacity of A
	 * Cb = capacity of B
	 * N = Goal
	 * fA = cost to fill A
	 * fB = cost to fill B
	 * eA = cost to empty A
	 * eB = cost to empty B
	 * pAB = cost to pour A to B
	 * pBA = cost to pour B to A
	*/
	int Ca, Cb, N, fA, fB, eA, eB, pAB, pBA;
	//Contains all vertexes created
	private Vector<JugNode> vertices = new Vector<JugNode>();

	
	
	//Constructor
	public Jug(int Ca, int Cb, int N, int fA, int fB, int eA, int eB, int pAB, int pBA){
		
		//Assign jug fields
		this.Ca = Ca;
		this.Cb = Cb;
		this.N = N;
		this.fA = fA;
		this.fB = fB;
		this.eA = eA;
		this.eB = eB;
		this.pAB = pAB;
		this.pBA = pBA;
	}
	
	private static class JugNode{
		//JugNode Fields
		int jugA;
		int jugB;
		int total_cost;
		Vector<String> list_of_performed_actions = null;
		Vector<JugNode> neighbors = null;

		//JugNode Constructor
		public JugNode(int jugA, int jugB, int total_cost){
			this.jugA = jugA;
			this.jugB = jugB;
			this.total_cost = total_cost;
			this.neighbors = new Vector<JugNode>();
			this.list_of_performed_actions = new Vector<String>();
		}
	}
	
	// Solve() is used to check the input and find the solution if one exists
	// returns 0 if input is valid but a solution does not exist.
	// returns 1 if solution is found and also prints solution
	int Solve(){
		// returns -1 if the input is invalid.
		if(Ca <= 0 || Ca > Cb){
			System.out.println("Please select Ca that is: 0 < Ca <= Cb");
			return -1;
		}
		if(Cb < N || Cb > 1000){
			System.out.println("Please select Cb that is: N <= Cb <= 1000");
			return -1;
		}
		
		//create initial JugNode
		JugNode initial_jugs = new JugNode(0, 0, 0);
		vertices.add(initial_jugs);
		//Reference for creating new JugNodes
		JugNode new_jugs;

		//Queue to facilitate going through and finding the solution
		Vector<JugNode> queue = new Vector<JugNode>();
		queue.add(initial_jugs);
		JugNode current_jugs = null;
		
		//Keeps track of all solutions
		Vector<JugNode> solutions = new Vector<JugNode>();
		
		while(queue.size() > 0){
			current_jugs = queue.get(0);
			//dequeue current vertex
			queue.remove(0);
			
			//Perform actions of change
			//Empty jug A
			if(current_jugs.jugA > 0){
				new_jugs = new JugNode(0, current_jugs.jugB, current_jugs.total_cost + eA);
				
				//If the new JugNode is the goal then print out the list of actions and cost
				if(checkSolution(new_jugs)){
					new_jugs.list_of_performed_actions.addAll(current_jugs.list_of_performed_actions);
					new_jugs.list_of_performed_actions.add("empty A");
					
					current_jugs.neighbors.add(new_jugs);
					vertices.add(new_jugs);
					solutions.add(new_jugs);
				}
				//As long as Jug combination doesn't already exist, added to the graph and the queue
				else if(checkExistence(new_jugs)){
					new_jugs.list_of_performed_actions.addAll(current_jugs.list_of_performed_actions);
					new_jugs.list_of_performed_actions.add("empty A");
					
					current_jugs.neighbors.add(new_jugs);
					vertices.add(new_jugs);
					queue.add(new_jugs);
				}
			}
			//Empty jug B
			if(current_jugs.jugB > 0){
				new_jugs = new JugNode(current_jugs.jugA, 0, current_jugs.total_cost + eB);
								
				if(checkSolution(new_jugs)){
					new_jugs.list_of_performed_actions.addAll(current_jugs.list_of_performed_actions);
					new_jugs.list_of_performed_actions.add("empty B");
					
					current_jugs.neighbors.add(new_jugs);
					vertices.add(new_jugs);
					solutions.add(new_jugs);
				}
				else if(checkExistence(new_jugs)){
					new_jugs.list_of_performed_actions.addAll(current_jugs.list_of_performed_actions);
					new_jugs.list_of_performed_actions.add("empty B");
					
					current_jugs.neighbors.add(new_jugs);
					vertices.add(new_jugs);
					queue.add(new_jugs);
				}
			}
			//Fill jug A
			if(current_jugs.jugA < Ca){
				new_jugs = new JugNode(Ca, current_jugs.jugB, current_jugs.total_cost + fA);
								
				if(checkSolution(new_jugs)){
					new_jugs.list_of_performed_actions.addAll(current_jugs.list_of_performed_actions);
					new_jugs.list_of_performed_actions.add("fill A");
					
					current_jugs.neighbors.add(new_jugs);
					vertices.add(new_jugs);
					solutions.add(new_jugs);
				}
				else if(checkExistence(new_jugs)){
					new_jugs.list_of_performed_actions.addAll(current_jugs.list_of_performed_actions);
					new_jugs.list_of_performed_actions.add("fill A");
					
					current_jugs.neighbors.add(new_jugs);
					vertices.add(new_jugs);
					queue.add(new_jugs);
				}
			}
			//Fill jug B
			if(current_jugs.jugB < Cb){
				new_jugs = new JugNode(current_jugs.jugA, Cb, current_jugs.total_cost + fB);
				
				if(checkSolution(new_jugs)){
					new_jugs.list_of_performed_actions.addAll(current_jugs.list_of_performed_actions);
					new_jugs.list_of_performed_actions.add("fill B");
					
					current_jugs.neighbors.add(new_jugs);
					vertices.add(new_jugs);
					solutions.add(new_jugs);
				}
				else if(checkExistence(new_jugs)){
					new_jugs.list_of_performed_actions.addAll(current_jugs.list_of_performed_actions);
					new_jugs.list_of_performed_actions.add("fill B");
					
					current_jugs.neighbors.add(new_jugs);
					vertices.add(new_jugs);
					queue.add(new_jugs);
				}
			}
			//Pour water from A to B
			if(current_jugs.jugA > 0 && current_jugs.jugB < Cb){
				int a = current_jugs.jugA;
				int b = current_jugs.jugB;
				
				while(a > 0 && b < Cb){
					a--;
					b++;
				}
				
				new_jugs = new JugNode(a, b, current_jugs.total_cost + pAB);
				
				if(checkSolution(new_jugs)){
					new_jugs.list_of_performed_actions.addAll(current_jugs.list_of_performed_actions);
					new_jugs.list_of_performed_actions.add("pour A B");
					
					current_jugs.neighbors.add(new_jugs);
					vertices.add(new_jugs);
					solutions.add(new_jugs);
				}
				else if(checkExistence(new_jugs)){
					new_jugs.list_of_performed_actions.addAll(current_jugs.list_of_performed_actions);
					new_jugs.list_of_performed_actions.add("pour A B");
					
					current_jugs.neighbors.add(new_jugs);
					vertices.add(new_jugs);
					queue.add(new_jugs);
				}
			}
			//Pour water from B to A
			if(current_jugs.jugB > 0 && current_jugs.jugA < Ca){
				int a = current_jugs.jugA;
				int b = current_jugs.jugB;
				
				while(b > 0 && a < Ca){
					a++;
					b--;
				}
				
				new_jugs = new JugNode(a, b, current_jugs.total_cost + pBA);
				
				if(checkSolution(new_jugs)){
					new_jugs.list_of_performed_actions.addAll(current_jugs.list_of_performed_actions);
					new_jugs.list_of_performed_actions.add("pour B A");
					
					current_jugs.neighbors.add(new_jugs);
					vertices.add(new_jugs);
					solutions.add(new_jugs);
				}		
				else if(checkExistence(new_jugs)){
					new_jugs.list_of_performed_actions.addAll(current_jugs.list_of_performed_actions);
					new_jugs.list_of_performed_actions.add("pour B A");
					
					current_jugs.neighbors.add(new_jugs);
					vertices.add(new_jugs);
					queue.add(new_jugs);
				}
			}
			
		}
		
		if(solutions.size() > 0){
			int i = findSolution(solutions);
			printOutput(solutions.get(i));
			return 1;
		}
		else{
			//In event no solution is found for given values of Ca, Cb, and N.
			System.out.println("No solution found");
			return 0;
		}
		
	}
	
	//Used to make sure new JugNodes do not already exist.
	private boolean checkExistence (JugNode j){
		for(int i = 0; i < vertices.size(); i++){
			if(j.jugA == vertices.get(i).jugA && j.jugB == vertices.get(i).jugB){
				return false;
			}
		}
		return true;
	}
	
	//Used to see if solution has been found
	private boolean checkSolution (JugNode j){
		if(j.jugA == 0 && j.jugB == N){
			return true;
		}
		else{
			return false;
		}
	}
	
	private void printOutput(JugNode j){
		for(int i = 0; i < j.list_of_performed_actions.size(); i++){
			System.out.println(j.list_of_performed_actions.get(i));
		}
		System.out.println("success "+j.total_cost+"\n");
	}
	
	private int findSolution(Vector<JugNode> j){
		int index = 0;
		int cost = j.get(0).total_cost;
		
		for(int i = 1; i < j.size(); i++){
			if(cost > j.get(i).total_cost){
				index = i;
				cost = j.get(i).total_cost;
			}
		}
		
		return index;
	}
}
