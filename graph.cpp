/* Graph Class Definitions - Akhil Baidya

Date of Submission: 5/31/24

Notes: This file defines the functions inside the Graph Class. It defines how to add/remove a vertex and edge, how to print out the adjacency list (as a list and table), and how to give the shortest path between two vertices.

Sources:
Referred to Professor Fant's video lectures embedded in Canvas (Topic 11: Heaps and Graphs) to understand what Graphs are and to implement it as an array of structs that contain a vertex and linked list of connections (edges). I also referred to Mr. Galbraith's video on Graphs, https://www.youtube.com/watch?v=j6u4V2Wu-QI, to understand Graph adjacency lists better (and how directed graphs don't have bi-directional connections). Finally, I referred to the video on Djkistra's Algorithm, https://www.youtube.com/watch?v=pVfj6mxhdMw, by youtube channel "Computer Science" to understand the algorithm.  
*/

#include <iostream>
#include <cstring>
#include "graph.h"

using namespace std;

//Constructor:
graph::graph() {
  //Set the Adjacency List as empty, since there are no vertices:
  for (int i = 0; i < 20; i++) {
    AdjList[i] = NULL; 
  }
}

//Destructor:
graph::~graph() {
}

//The addVertex function creates and names a vertex and then adds it to the graph (the adjacency list):
void graph::addVertex(char input) {
  //Create location struct out of a vertex:

  vertex wrapInput;
  wrapInput.label = input; //created vertex
  
  location* loc = new location();
  loc -> visited = 0;
  loc -> point = wrapInput;
  loc -> connections = NULL; //created location


  //Add location to next empty spot in adjacency list:
  int i = 0;

  while (AdjList[i] != NULL && i != 20) {
    i+=1; //traverse
  }

  if (i != 20) {
    AdjList[i] = loc; //add location
  }

  else {
    cout << "Out of Space" << endl;
    return;
  }
}

//The remVertex function takes in the name of a vertex and removes it and connections to it from the graph (adjacency list):
void graph::remVertex(char input) { 
  //First remove vertex from list:

  int i = 0;
  while ((AdjList[i] == NULL || (AdjList[i] != NULL && (AdjList[i] -> point).label != input)) && i != 20) {
    i++; //traverse until reaching the desired vertex (has the same name as inputted)
  }
  if (i != 20) {
    AdjList[i] = NULL;
  }
 
  //Next remove all connections to that vertex:
  for (int j = 0; j < 20; j++) { //for each vertex
    if (AdjList[j] != NULL && AdjList[j] -> connections != NULL) {
      
      //Remove edge from connections linked list
      edge* previous = NULL;
      edge* current = AdjList[j] -> connections;

      if (current != NULL && current -> to -> label == input) { //if the first connection points to the removed vertex, remove it
	AdjList[j] -> connections = current -> next;
      }
      
      else { 
	while (current != NULL && current -> to -> label != input) {
	  previous = current;
	  current = current -> next; //traverse the linked list of connections until one points to the removed vertex
      }
	if (current != NULL && current == AdjList[j] -> connections) { //if the first connections points, remove it
	  AdjList[j] -> connections = current -> next;
	}
	else if (current != NULL)  { //otherwise, disconnect edge from linked list
	  previous -> next = current -> next;
	}
      }
    }
  }
}

/*The addEdge function takes in the names of two vertices and a weight. It creates an edge between those vertices of that weight, stored in a linked list in the graph (adjacency list)*/
void graph::addEdge(char first, char second, int input) {
  //First check if first is in the table and get its index:
  
  int i = 0;
  int firstIndex = 0;
  while ((AdjList[i] == NULL || (AdjList[i] != NULL && (AdjList[i] -> point).label != first)) && i != 20) {
    i++; //traverse until the first vertex is found
  }
  if (i != 20 && AdjList[i] != NULL) {
    firstIndex = i;
  }
  else {
    cout << "First vertex doesn't exist" << endl;
    return;
  }

  //Second check if second is in table and get its index:

  i = 0;
  int secIndex = 0;
  while ((AdjList[i] == NULL || (AdjList[i] != NULL && (AdjList[i] -> point).label != second)) && i != 20) {
    i++; //traverse until the second vertex is found
  }
  if (i != 20 && AdjList[i] != NULL) {
    secIndex = i;
  }
  else {
    cout << "Second vertex doesn't exist" << endl;
    return;
  }

  //Now, if both exist, update connection on the first

  edge* toSecond = new edge();
  toSecond -> to = &(AdjList[secIndex] -> point);
  toSecond -> weight = input; //create edge that points to the second vertex and has the inputted weight
  
  edge* current1 = AdjList[firstIndex] -> connections;
  if (current1 == NULL) {
    AdjList[firstIndex] -> connections = toSecond; //if the first vertex has no connections, simply make edge head of linked list
  }
  else {
    while (current1 -> next != NULL) {
      current1 = current1 -> next; //otherwise, traverse until reaching the end of linked list of connections
    }
    current1 -> next = toSecond;
  }
  return;
}

/*The remEdge function takes in the names of two vertices and deletes the edge from the first vertex's linked list of connections that connects to the second vertex*/
void graph::remEdge(char first, char second) {
  //First check if first is in table and get its index:
  
  int i = 0;
  int firstIndex = 0;
  while ((AdjList[i] == NULL || (AdjList[i] != NULL && (AdjList[i] -> point).label != first)) && i != 20) {
    i++; //traverse until first vertex is found
  }
  if (i != 20 && AdjList[i] != NULL) {
    firstIndex = i;
  }
  else {
    cout << "First vertex doesn't exist" << endl;
    return;
  }

  //Second check if second is in table and get its index:
  i = 0;
  int secIndex = 0;
  while ((AdjList[i] == NULL || (AdjList[i] != NULL && (AdjList[i] -> point).label != second)) && i != 20) {
    i++; //traverse until second vertex is found
  }
  if (i != 20 && AdjList[i] != NULL) {
    secIndex = i;
  }
  else {
    cout << "Second vertex doesn't exist" << endl;
    return;
  }
  
  //Now, if both exist, update connection on the first
  edge* previous1 = NULL;
  edge* current1 = AdjList[firstIndex] -> connections;

  while (current1 != NULL && current1 -> to -> label != second) {
    previous1 = current1;
    current1 = current1 -> next;
  }

  if (current1 != NULL && current1 == AdjList[firstIndex] -> connections) {
    AdjList[firstIndex] -> connections = current1 -> next; //remove connection to second vertex
  }
  else if (current1 != NULL) {
    previous1 -> next = current1 -> next;
  }
  return;
}

/*The print function prints out the array of structs containing the vertices and their connections. It also prints out this data in the form of an adjacency table, where existing connections read the weight of the connection. The names on the left side of the table are the "from" vertices and the names on the top of the table are the "to" vertices (this is a directed graph) */
void graph::print() {

  //Print out Adjacency List:
  cout << "List of elements: " << endl;
  for (int i = 0; i < 20; i++) { //for each vertex

    if (AdjList[i] != NULL) {
      cout << "Visited: " << AdjList[i] -> visited << " "; //print out whether it is visited

      cout << "Vertex: " << (AdjList[i] -> point).label << " "; //print out the vertex name

      edge* current = AdjList[i] -> connections; //print out its connections
      
      while (current != NULL) {
	cout << "[to: " << current -> to -> label << ", weight: " << current -> weight << "]";
	current = current -> next; //traverse down linked list of connections to print
      }
      cout << endl;
    }

    else {
      cout << "Empty" << endl;
    }  
  }

  //Print out Table:
  cout << "Table: " << endl;
  
  //Column names:
  cout << "| |";

  for (int i = 0; i < 20; i++) {
    cout << "|";
    if (AdjList[i] != NULL) {
      cout << (AdjList[i] -> point).label; //print each vertex's name
    }
    else {
      cout << " ";
    }
    cout << "|";
  }
  cout << endl;

  //The Rows:
  for (int i = 0; i < 20; i++) {

    //If a vertex exists:
    if (AdjList[i] != NULL) {
      cout << "|" << (AdjList[i] -> point).label << "|"; //print out vertex name

      for (int j = 0; j < 20; j++) { //loop and print out weights of connections to each other vertex
	cout << "|";
	int weight = -1;
	edge* current = AdjList[i] -> connections;
	
	if (current == NULL) { //if there is no connection
	  cout << " ";
	}

	else if (AdjList[j] == NULL) { //if there is no other vertex currently being looked at
	  cout << " ";
	}
	
	else if (current != NULL && current -> to -> label == (AdjList[j] -> point).label) {
	  cout << current -> weight; //print out weight of connection to AdjList[j] (the other vertex) if connection is head of linked list 
	}

	else if (current != NULL) {
	  while (current != NULL && current -> to -> label != (AdjList[j] -> point).label) {
	    current = current -> next; //find spot in linked list with connection to AdjList[j]
	  }
	  if (current != NULL) {
	    cout << current -> weight; //print out weight
	  }
	  else {
	    cout << " ";
	  }
	}
	cout << "|";
      } 
    }

    else if (AdjList[i] == NULL) { //don't print out vertex if it doesn't exist in the first place
      cout << "| |";
      for (int i = 0; i < 20; i++) {
	cout << "| |";
      }
    }
    cout << endl;
  }
  return;
}

/*The shortestPath function takes in the names of two vertices and prints out the shortest path from the first to the second vertex, if possible, using Dijkstra's Algorithm*/
void graph::shortestPath(char first, char last) {
  //First check validity of inputs (same code as in previous functions):

  //First check if first is in table and get its index:
  int i = 0;
  int firstIndex = 0;
  while ((AdjList[i] == NULL || (AdjList[i] != NULL && (AdjList[i] -> point).label != first)) && i != 20) {
    i++;
  }
  if (i != 20 && AdjList[i] != NULL) {
    firstIndex = i;
  }
  else {
    cout << "First vertex doesn't exist" << endl;
    return;
  }

  //Second check if second is in table and get its index:
  i = 0;
  int secIndex = 0;
  while ((AdjList[i] == NULL || (AdjList[i] != NULL && (AdjList[i] -> point).label != last)) && i != 20) {
    i++;
  }
  if (i != 20 && AdjList[i] != NULL) {
    secIndex = i;
  }
  else {
    cout << "Second vertex doesn't exist" << endl;
    return;
  }

  //Implement Dijkstra's Algorithm:

  //All vertices are first unvisted:
  for (int i = 0; i < 20; i++) {
    if (AdjList[i] != NULL) {
      AdjList[i] -> visited = 0; //unvisited
    }
  }
  
  //Other things to keep track of:
  char prevVert[20]; //list of vertices visited before a vertex in AdjList in the shortest path
  int dist[20]; //list of distances (for each vertex) from the first vertex inputted

  //All distances are nearly infinite initially and there are no previous vertices:
  for (int i = 0; i < 20; i++) {
    dist[i] = 9999; //nearly infinite distance
    prevVert[i] = ' ';
  }

  //Set-up:
  dist[firstIndex] = 0; //distance away from self must be 0;
  int previous = firstIndex; 
  int visiting = firstIndex; //these indices will help indicate to which vertex the algorithm is moving
  
  //In a loop (until all vertices in a path have been visited), update dist and prevVert array:
  bool stop = true;
  
  while (stop) {
    if (AdjList[visiting] != NULL) {

      //Debugging:
      //cout << "visiting" << (AdjList[visiting] -> point).label << endl;
      //cout << (AdjList[visiting] -> point).label << endl;

      AdjList[visiting] -> visited = 1; //visit vertex
      edge* current = AdjList[visiting] -> connections; //get its connections
      edge* best = NULL; //will need to find least costly connection to determine which vertex to go to for next iteration in loop
      int bestInd = -1; //index of best vertex (least costly)

      //Visit each connection:
      while (current != NULL) {

	//Debugging:
	//cout << "in loop" << endl;
	//cout << "checking connection to " << current -> to -> label << endl;
	
	for (int j = 0; j < 20; j++) {
	  if (AdjList[j] != NULL && (AdjList[j] -> point).label == current -> to -> label) { //find index of vertex pointed to

	    //Debugging:
	    /*cout << "found " << (AdjList[j] -> point).label << "at index " << j << endl;
	    cout << "prev: " << endl;
	    
	    if (AdjList[previous] != NULL) {
	      cout << (AdjList[previous] -> point).label << endl;
	    }
	    cout << "dist" << dist[previous] << endl;
	    
	    cout << "current" << endl;
	    if (AdjList[visiting] != NULL) {
	      cout << (AdjList[visiting] -> point).label << endl;
	    }
	    cout << current -> weight << "daDist" << endl;
	    */
	    
	    int count = (current -> weight) + dist[visiting]; //get distance from first vertex inputted
	    //cout << "distance from init" << count << endl; (debugging)

	    if (count < dist[j]) { //update shortest distance from first vertex (if a new shortest is found)
	      //cout << "update" << endl; (debugging)
	      dist[j] = count;
	      prevVert[j] = (AdjList[visiting] -> point).label;
	      //cout << "went to " << (AdjList[j] -> point).label << "from" << prevVert[j]; (debugging)
	    }
	    
	    //Keep this edge as the best/least costly connection if the vertex it connects to (AdjList[j]) is unvisted and no best edge has been saved:
	    if (best == NULL && AdjList[j] -> visited == 0) {
	      best = current;
	      bestInd = j;
	      //cout << "best index is " << bestInd << endl;
	      //cout << "this is where " << (AdjList[bestInd] -> point).label << endl; (debugging)
	    }

	    //Same as above, but when there is a best currently saved, the new edge must have a smaller weight to replace it:
	    else if (best != NULL && AdjList[j] -> visited == 0 && current -> weight < best -> weight) {
	      //cout << "found better:" << endl;
	      //cout << current -> to -> label << endl; (debugging)
	      best = current;
	      bestInd = j;
	      //cout << "best index is " << bestInd << endl;
	      //cout << "this is where " << (AdjList[bestInd] -> point).label << endl; (debugging)
	    }
	  }
	}
	current = current -> next; //visit next connection
	//cout << "next loop will start" << endl; (debugging)
      }
      
      //Now, after this secondary while loop, we have the best edge!
      //cout << "best: " << bestInd << endl;
      //cout << best -> to -> label << endl; (debugging)

      //Set previous vertex as the one currently being visited:
      if (best != NULL && bestInd != -1) {
	previous = visiting;
	//cout << "previous: " << (AdjList[previous] -> point).label << endl; (debugging)
	visiting = bestInd; //move on to where the best edge points to
	//cout << "going to visit: " << (AdjList[visiting] -> point).label << endl; (debugging)
      }

      //End loop if no new connection is found:
      else {
	stop = false;
      }
    } 
  }

  //Table of Vertices, Vertices visited before them, and Distance from first vertex:
  cout << "Table Check (Vertices, Vertices visited before them, Distance from first vertex)" << endl;
  for (int i = 0; i < 20; i++) {
    if (AdjList[i] != NULL) {
      cout << (AdjList[i] -> point).label << "|" << prevVert[i] << "|" << dist[i] << "|" << endl;
    }
  }
  
  //Reading the Shortest Path out:
  
  int shortLen = dist[secIndex]; //shortest distance

  /*
    Debugging:
  cout << shortLen << endl;
  cout << prevVert[secIndex] << endl;  
  */
  
  char path[20]; //the path
  int pathEnd = 0; //index in path array where it ends
  int toAdd = secIndex; //index of vertex to add to the path

  //Set the first element of the path array as the vertex reached: 
  path[0] = (AdjList[secIndex] -> point).label;
  pathEnd = pathEnd + 1;

  /*
    Debugging:
  cout << path[0] << endl;
  cout << (AdjList[secIndex] -> point).label << endl;
  */
  
  int index = 0;

  //Traverse down the previous vertices (the previous vertex of the last vertex reached and so on, until the first vertex):
  while (toAdd != firstIndex && prevVert[toAdd] != ' ') {
    path[pathEnd] = prevVert[toAdd]; //add vertex to the path
    index = 0;
    
    while ((AdjList[index] == NULL || (AdjList[index] != NULL && (AdjList[index] -> point).label != prevVert[toAdd])) && index < 20) {
      index++; //find index of previous vertex
    }
    
    if (AdjList[index] != NULL && index < 20) {
      toAdd = index; //set next index to look at as the previous vertex's index
    }
    pathEnd++; //pathEnd helps add to the end of the array (the empty spot right after the most recent entry)
    //cout << (AdjList[secIndex] -> point).label << endl; (debugging)
  }
  
  //cout << (AdjList[secIndex] -> point).label << endl; (deubgging)

  //Print out path:
  if (shortLen != 9999) {
    
    cout << "The shortest path from " << (AdjList[firstIndex] -> point).label << "to " << (AdjList[secIndex] -> point).label << ":"<< endl;
    
    for (int i = pathEnd - 1; i > -1; i--) {
      cout << path[i] << "-"; //print out path
      
    }
    cout << endl;
    cout << "With distance: " << shortLen << endl; //print out weight of path
  }
  
  else {
    cout << "No such path" << endl; //a distance of 9999 means that the vertices are not connected (is the equivalent of infinity in this program)

    //In other words, no total sum of edge weights in any path should exceed 9999 in this program (this serves as an upper limit)
  }
  return;
}
