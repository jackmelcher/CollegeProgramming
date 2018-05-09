/**
 * Course: EECS 114 Fall 2015
 *
 * First Name: Jack
 * Last Name: Melcher
 * Lab Section: 1A
 * email address: jmelcher@uci.edu
 *
 *
 * Assignment: Lab 8
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
		Graph graph;
		
		
		if(args.length < 1 || args.length > 1){
			System.out.println("Exectue using the following format:");
			System.out.println("java Main input_file");
		}
		else if(args.length == 1){
			graph = new Graph(args[0]);
			graph.display();
			System.out.println();
			
			//Source Vertex: Nile
			graph.set_levels(0);
			graph.display_levels();
			System.out.println("is_Connected with source vertex 0: "+graph.is_connected(0));
			System.out.println();

			//Source Vertex: Mondavi
			graph.set_levels(1);
			graph.display_levels();
			System.out.println("is_Connected with source vertex 1: "+graph.is_connected(1));
			System.out.println();

			//Source Vertex: Lodi
			graph.set_levels(2);
			graph.display_levels();
			System.out.println("is_Connected with source vertex 2: "+graph.is_connected(2));
			System.out.println();

			//Source Vertex: Rivoli
			graph.set_levels(3);
			graph.display_levels();
			System.out.println("is_Connected with source vertex 3: "+graph.is_connected(3));
			System.out.println();

			//Source Vertex: Pyramids
			graph.set_levels(4);
			graph.display_levels();
			System.out.println("is_Connected with source vertex 4: "+graph.is_connected(4));
			System.out.println();

			//Source Vertex: Zurich
			graph.set_levels(5);
			graph.display_levels();
			System.out.println("is_Connected with source vertex 5: "+graph.is_connected(5));
			System.out.println();

			//Source Vertex: Marengo
			graph.set_levels(6);
			graph.display_levels();
			System.out.println("is_Connected with source vertex 6: "+graph.is_connected(6));
			System.out.println();

			//Source Vertex: Friedland
			graph.set_levels(7);
			graph.display_levels();
			System.out.println("is_Connected with source vertex 7: "+graph.is_connected(7));
			System.out.println();
		}
	}
}
