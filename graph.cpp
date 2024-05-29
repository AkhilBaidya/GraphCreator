/*graph class definitions*/

#include <iostream>
#include <cstring>
#include "graph.h"

using namespace std;

//Constructor:
graph::graph() {
  for (int i = 0; i < 20; i++) {
    AdjList[i] = NULL; 
  }
}

graph::~graph() {
}

//Adding a vertex to the graph (max 20 allowed):
void graph::addVertex(char input) {

  cout << "entered function:" << endl;
  //Create location struct out of vertex

  vertex wrapInput;
  wrapInput.label = input; //vertex
  
  location* loc = new location();
  loc -> visited = 0;
  loc -> point = wrapInput;
  loc -> connections = NULL; //create location


  //Add location to adjacency list
  
  int i = 0;

  while (AdjList[i] != NULL && i != 20) {
    i+=1;
  }

  if (i != 20) {
    cout << "here" << endl;
    AdjList[i] = loc;
  }

  else {
    cout << "Out of Space" << endl;
    return;
  }
}

void graph::remVertex(char input) { //not working
  //First remove vertex from list:
  int i = 0;
  while (AdjList[i] != NULL && (AdjList[i] -> point).label != input && i != 20) {
    i++;
  }
  if (i != 20) {
    AdjList[i] = NULL;
  }
  cout << "removed vertex now remove connections" << endl;
  //Next remove all connections to that vertex:
  for (int j = 0; j < 20; j++) {
    if (AdjList[j] != NULL && AdjList[j] -> connections != NULL) {
      cout << "valid" << endl;
      //remove edge from connections linked list
      edge* previous = NULL;
      edge* current = AdjList[j] -> connections;

      if (current != NULL && current -> to -> label == input) {
	AdjList[j] -> connections = NULL;
      }
      else { 
	while (current != NULL && current -> to -> label != input) {
	previous = current;
	current = current -> next;
      }
      if (current != NULL && current == AdjList[j] -> connections) {
	AdjList[j] -> connections = current -> next;
      }
      else if (current != NULL) {
	previous -> next = current -> next;
      }
    }

    }
  }
}

void graph::addEdge(char first, char second, int input) {
  //First check if first is in table and get its index
  int i = 0;
  int firstIndex = 0;
  while (AdjList[i] != NULL && (AdjList[i] -> point).label != first && i != 20) {
    cout << "going" << endl;
    i++;
  }
  if (i != 20 && AdjList[i] != NULL) {
    firstIndex = i;
  }
  else {
    cout << "First vertex doesn't exist" << endl;
    return;
  }

  //Second check if second is in table and get its index
  i = 0;
  int secIndex = 0;
  while (AdjList[i] != NULL && (AdjList[i] -> point).label != second && i != 20) {
    cout << "going 2" << endl;
    i++;
  }
  cout << "exited loop" << endl;
  if (i != 20 && AdjList[i] != NULL) {
    secIndex = i;
    cout << "met criteria" << endl;
  }
  else {
    cout << "Second vertex doesn't exist" << endl;
    return;
  }

  //cout << firstIndex;
  //cout << secIndex;

  //Now, if both exist, update connection on the first
  edge* toSecond = new edge();
  toSecond -> to = &(AdjList[secIndex] -> point);
  toSecond -> weight = input;
  
  edge* current1 = AdjList[firstIndex] -> connections;
  if (current1 == NULL) {
    cout << "here" << endl;
    AdjList[firstIndex] -> connections = toSecond;
    cout << "did" << endl;
  }
  else {
    while (current1 -> next != NULL) {
      current1 = current1 -> next;
    }

    current1 -> next = toSecond;
  }

  /*
  //Now, if both exist, update connection on the second
  edge* toFirst = new edge();
  toFirst -> to = &(AdjList[firstIndex] -> point);
  toFirst -> weight = input;
  
  edge* current2 = AdjList[secIndex] -> connections;
  if (current2 == NULL) {
    cout << "here" << endl;
    AdjList[secIndex] -> connections = toFirst;
  }
  else {
    while (current2 -> next != NULL) {
      current2 = current2 -> next;
    }

    current2 -> next = toFirst;
    }*/

  return;
}

void graph::remEdge(char first, char second) {
  //First check if first is in table and get its index
  int i = 0;
  int firstIndex = 0;
  while (AdjList[i] != NULL && (AdjList[i] -> point).label != first && i != 20) {
    i++;
  }
  if (i != 20 && AdjList[i] != NULL) {
    firstIndex = i;
  }
  else {
    cout << "First vertex doesn't exist" << endl;
    return;
  }

  //Second check if second is in table and get its index
  i = 0;
  int secIndex = 0;
  while (AdjList[i] != NULL && (AdjList[i] -> point).label != second && i != 20) {
    i++;
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

  /*
  
  //Now, if both exist, update connection on the second
  edge* previous2 = NULL;
  edge* current2 = AdjList[secIndex] -> connections;

  while (current2 != NULL && current2 -> to -> label != first) {
    previous2 = current2;
    current2 = current2 -> next;
  }

  if (current2 != NULL && current2 == AdjList[secIndex] -> connections) {
    AdjList[secIndex] -> connections = current2 -> next; //remove connection to second vertex
  }
  else if (current2 != NULL) {
    previous2 -> next = current2 -> next;
    }*/
  return;
}

void graph::print() {
  /*for (int i = 0; i < 20; i++) {

    if (AdjList[i] != NULL) {
      cout << "Visited: " << AdjList[i] -> visited << " ";

      cout << "Vertex: " << (AdjList[i] -> point).label << " ";

      edge* current = AdjList[i] -> connections;
      
      while (current != NULL) {
	cout << "[to: " << current -> to -> label << ", weight: " << current -> weight << "]";
	current = current -> next;
      }
      cout << endl;
    }

    else {
      cout << "Empty" << endl;
    }
    
  }*/

  //column names:
  cout << "| |";
  for (int i = 0; i < 20; i++) {
    cout << "|";

    if (AdjList[i] != NULL) {
      cout << (AdjList[i] -> point).label;
    }
    else {
      cout << " ";
    }

    cout << "|";
  }
  cout << endl;

  //cout << "done with header" << endl;
  //the rows:
  for (int i = 0; i < 20; i++) {
    //cout << "row" << i;
    //cout << "another attempt byt";
    //cout << "bob";
    //cout << "why";
    if (AdjList[i] != NULL) {
      //cout << "nonfunny";
      cout << "|" << (AdjList[i] -> point).label << "|";

      //then loop and print out connections.

      for (int j = 0; j < 20; j++) {
	cout << "|";
	int weight = -1;
	edge* current = AdjList[i] -> connections;
	
	if (current == NULL) {
	  cout << " ";
	}

	else if (AdjList[j] == NULL) {
	  cout << " ";
	}
	
	else if (current != NULL && current -> to -> label == (AdjList[j] -> point).label) {
	  //cout << "first connection found";
	  cout << current -> weight;
	}

	else if (current != NULL) {
	  //cout << "searching";
	  while (current != NULL && current -> to -> label != (AdjList[j] -> point).label) {
	    current = current -> next;
	  }
	  //cout << "ended search";
	  if (current != NULL) {
	    //cout << "here's the weight";
	    cout << current -> weight;
	  }
	  else {
	    cout << " ";
	  }
	  }
	cout << "|";
      } 
    }

    else if (AdjList[i] == NULL) {
      cout << "| |";
      for (int i = 0; i < 20; i++) {
	cout << "| |";
      }
    }
    cout << endl;
  }
  
  return;
}

void graph::shortestPath(char first, char last) {
  //Going to use Djkistra's Algorithm here..

  //First check validity of inputs:

  //First check if first is in table and get its index
  int i = 0;
  int firstIndex = 0;
  while (AdjList[i] != NULL && (AdjList[i] -> point).label != first && i != 20) {
    i++;
  }
  if (i != 20 && AdjList[i] != NULL) {
    firstIndex = i;
  }
  else {
    cout << "First vertex doesn't exist" << endl;
    return;
  }

  //Second check if second is in table and get its index
  i = 0;
  int secIndex = 0;
  while (AdjList[i] != NULL && (AdjList[i] -> point).label != last && i != 20) {
    i++;
  }
  if (i != 20 && AdjList[i] != NULL) {
    secIndex = i;
  }
  else {
    cout << "Second vertex doesn't exist" << endl;
    return;
  }

  //cout << (AdjList[firstIndex] -> point).label << endl;
  //cout << (AdjList[secIndex] -> point).label << endl;

  //all vertices are first unvisted:
  for (int i = 0; i < 20; i++) {
    if (AdjList[i] != NULL) {
      AdjList[i] -> visited = 0; //unvisited
    }
  }
  cout << "made all unvisited :)" << endl;

  //other things to keep track of:
  char prevVert[20];
  int dist[20];

  for (int i = 0; i < 20; i++) {
    dist[i] = 9999; //nearly infinite distance initially
  }

  cout << "made infinite distances" << endl;

  dist[firstIndex] = 0; //distance away from self;
  int previous = firstIndex;
  int visiting = firstIndex;
  cout << (AdjList[firstIndex] ->point).label << "first" << endl;
 
  //loop and update this table
  bool stop = true;
  
  while (stop) {
    if (AdjList[visiting] != NULL) { //edit here
      cout << "visiting" << (AdjList[visiting] -> point).label << endl;
      //cout << (AdjList[visiting] -> point).label << endl;
      AdjList[visiting] -> visited = 1;
	edge* current = AdjList[visiting] -> connections;
	edge* best = NULL;
	int bestInd = -1;

	while (current != NULL) {
	  cout << "in loop" << endl;
	  //cout << "checking connection to " << current -> to -> label << endl;
	  
	  for (int j = 0; j < 20; j++) {
	    if (AdjList[j] != NULL && (AdjList[j] -> point).label == current -> to -> label) {

	      //cout << "found " << (AdjList[j] -> point).label << "at index " << j << endl;

	      int count = (current -> weight) + dist[previous];

	      if (count < dist[j]) { //update shortest distance from first vertex (if a new shortest is found)
		cout << "update" << endl;
		dist[j] = count;
		prevVert[j] = (AdjList[visiting] -> point).label;
		cout << "went to " << (AdjList[j] -> point).label << "from" << prevVert[j];
	      }

	      //keep it as best if it is unvisted.

	      if (best == NULL && AdjList[j] -> visited == 0) {
		best = current;
		bestInd = j;
		//cout << "best index is " << bestInd << endl;
		//cout << "this is where " << (AdjList[bestInd] -> point).label << endl;
	      }

	      else if (best != NULL && AdjList[j] -> visited == 0 && current -> weight < best -> weight) {
		//cout << "found better:" << endl;
		//cout << current -> to -> label << endl;
		best = current;
		bestInd = j;
		//cout << "best index is " << bestInd << endl;
		//cout << "this is where " << (AdjList[bestInd] -> point).label << endl;
	      }


	    }
	  }
	  current = current -> next;
	  cout << "next loop will start" << endl;
	}

	//we have the best edge!
	cout << "best: " << bestInd << endl;
	//cout << best -> to -> label << endl;
	//set previous to current
	if (best != NULL && bestInd != -1) {
	previous = visiting;
	cout << "previous: " << (AdjList[previous] -> point).label << endl;
	visiting = bestInd;
	cout << "going to visit: " << (AdjList[visiting] -> point).label << endl;
	}

	else { //end loop if no new connection is found
	  stop = false;
	}

	//set current (visiting) to the one we are going to visit 
    } 
  }

  //Read it out:
  int shortLen = dist[secIndex];
  cout << shortLen << endl;
  cout << prevVert[secIndex] << endl;

  char path[20];
  int pathEnd = 0; //index in path where it ends
  int toAdd = secIndex;
  path[pathEnd] = (AdjList[secIndex] -> point).label;
  pathEnd++;

  cout << (AdjList[secIndex] -> point).label << endl;
  int index = 0;
  while (toAdd != firstIndex && prevVert[toAdd] != NULL) {
    path[pathEnd] = prevVert[toAdd];
    while (AdjList[index] != NULL && (AdjList[index] -> point).label != prevVert[toAdd] && index < 20) {
      index++;
    }

    if (AdjList[index] != NULL && index < 20) {
      toAdd = index;
    }
    pathEnd++;
    cout << (AdjList[secIndex] -> point).label << endl;
  }

  cout << (AdjList[secIndex] -> point).label << endl;
  if (shortLen != 9999) {

    cout << "The shortest path from " << (AdjList[firstIndex] -> point).label << "to " << (AdjList[secIndex] -> point).label << ":"<< endl;

  for (int i = pathEnd; i > 0; i--) {

    cout << path[i] << "-";
  
  }
  cout << endl;
  cout << "With distance: " << shortLen << endl;
  }

  else {
    cout << "No such path" << endl;
  }

  for (int i = 0; i < 20; i++) {
    cout << dist[i] << "|";
  }
  cout << endl;
  for (int i = 0; i < 20; i++) {
    if (AdjList[i] != NULL) {
    cout << (AdjList[i] -> point).label << endl;
    }
  }
  cout << endl;
  for (int i = 0; i < 20; i++) {
    cout << prevVert[i] << endl;
  }
  
  return;
}
