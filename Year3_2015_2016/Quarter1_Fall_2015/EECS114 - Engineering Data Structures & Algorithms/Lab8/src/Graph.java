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
 * Assignment: Lab 8
 * Filename : Graph.java
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
public class Graph {
	private static class Vertex{
		//Vertex Fields
		private Vector<String> neighbors = null;
		private int distance;
		private String label;
		//Vertex Constructors
		Vertex(String label){
			this.label = label;
			this.neighbors = new Vector<String>();
		}
		//Vertex Methods
	}
	//Graph Fields
	private Vertex[] vertices;
	
	//Graph Constructors
	public Graph(String input_file){
		build_graph(input_file);
	}
	//Graph Methods
	//member method, invoked from a class constructor. 
	//Reads the graph input file and instantiates the Graph object. 
	//Name of file is passed as a command line argument to main().  
	private void build_graph(String input_file){
		int numberOfVertices;
		int numberOfEdges;
		Vertex v;
		String currentVertex = null;
		String currentNeighbor = null;
		
		
		Scanner s;
		try {
			s = new Scanner(new FileReader(input_file));
			
			numberOfVertices = s.nextInt();
			numberOfEdges = s.nextInt();
			vertices = new Vertex[numberOfVertices];
			
			//Insert vertices into graph
			for(int i = 0; i < numberOfVertices; i++){
				v = new Vertex(s.next());
				vertices[i] = v;
			}
			//Insert vertices neighbors
			for(int i = 0; i < numberOfEdges; i++){
				currentVertex = s.next();
				currentNeighbor = s.next();
				for(int j = 0; j < numberOfVertices; j++){
					if(currentVertex.compareTo(vertices[j].label) == 0){
						vertices[j].neighbors.addElement(currentNeighbor);
					}
				}
			}	
			s.close();
		} 
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	//member method,  prints out the graph's adjacency list in the format below, 
	//i.e., the vertex label and its neighbors' labels are displayed.
	public void display(){
		for(int i = 0; i < vertices.length; i++){
			System.out.print(vertices[i].label+" -> ");
			for(int j = 0; j < vertices[i].neighbors.size(); j++){
				System.out.print(vertices[i].neighbors.get(j)+", ");
			}
			if(vertices[i].neighbors.size() == 0){
				System.out.println("empty");
			}
			else{System.out.print("\n");}
		}
	}
	//member method that prints out the graph's vertices with each vertex's distance from the source vertex. 
	//Format is a student design decision.
	public void display_levels(){
		for(int i = 0; i < vertices.length; i++){
			System.out.println("Vertex: "+vertices[i].label);
			System.out.println("Distance from source vertex: "+vertices[i].distance);
		}
	}
	//member method,  via a BFS traversal, this method should assign each individual vertex's distance 
	//to be equal to the number of hops that the vertex is from a source vertex.
	public void set_levels(int source_vertex){
		Vector<Vertex> graph_queue = new Vector<Vertex>();
		Vertex currentVertex = null;
		String currentNeighbor = null;
		
		//Reset distances
		for(int i = 0; i < vertices.length; i++){
			vertices[i].distance = -1;
		}
		
		//Establish source vertex
		vertices[source_vertex].distance = 0;
		graph_queue.add(vertices[source_vertex]);
		
		//BFS process
		while(graph_queue.size() > 0){
			currentVertex = graph_queue.get(0);
			//dequeue current vertex
			graph_queue.remove(0);
			//Loop through neighbors of current vertex
			for(int i = 0; i < currentVertex.neighbors.size(); i++){
				currentNeighbor = currentVertex.neighbors.get(i);
				//Loop though vertices array
				for(int j = 0; j < vertices.length; j++){
					//check to see if there is a neighbor match
					if(currentNeighbor.compareTo(vertices[j].label) == 0){
						//check to see if distance has been assigned
						if(vertices[j].distance == -1){
							//assign distance
							//vertices[j].distance = current_distance;
							vertices[j].distance = currentVertex.distance+1;

							//enqueue vertex that was assigned distance
							graph_queue.add(vertices[j]);
						}
					}
				}
			}
		}
		
		

		
	}
	//member method,  via a BFS traversal, checks if the entire graph (all vertices in G) 
	//can be visited starting at the source vertex. 
	public boolean is_connected(int source_vertex){
		boolean isConnected = true;
		
		Vector<Vertex> graph_queue = new Vector<Vertex>();
		Vertex currentVertex = null;
		String currentNeighbor = null;
		
		//Reset distances
		for(int i = 0; i < vertices.length; i++){
			vertices[i].distance = -1;
		}
		
		//Establish source vertex
		vertices[source_vertex].distance = 0;
		graph_queue.add(vertices[source_vertex]);
		
		//BFS process
		while(graph_queue.size() > 0){
			currentVertex = graph_queue.get(0);
			//dequeue current vertex
			graph_queue.remove(0);
			//Loop through neighbors of current vertex
			for(int i = 0; i < currentVertex.neighbors.size(); i++){
				currentNeighbor = currentVertex.neighbors.get(i);
				//Loop though vertices array
				for(int j = 0; j < vertices.length; j++){
					//check to see if there is a neighbor match
					if(currentNeighbor.compareTo(vertices[j].label) == 0){
						//check to see if distance has been assigned
						if(vertices[j].distance == -1){
							//assign distance
							vertices[j].distance = currentVertex.distance+1;

							//enqueue vertex that was assigned distance
							graph_queue.add(vertices[j]);
						}
					}
				}
			}
		}
		
		//Check to see if all vertices are connected
		for(int i = 0; i < vertices.length; i++){
			if(vertices[i].distance == -1){
				isConnected = false;
			}
		}
		
		return isConnected;
	}
	
	
}
