/*graph class definitions*/

#include <iostream>
#include <cstring>

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

  //Create location struct out of vertex

  vertex wrapInput;
  wrapInput.label = input; //vertex

  location* loc;
  loc -> visited = 0;
  loc -> point = wrapInput;
  loc -> connections = NULL; //create location


  //Add location to adjacency list
  
  int i = 0;

  while (AdjList[i] != NULL & i != 20) {
    i+=1;
  }

  if (i != 20) {
    AdjList[i] = loc;
  }

  else {
    cout << "Out of Space" << endl;
    return;
  }
}

void graph::remVertex(char input) {
  //First remove vertex from list:
  int i = 0;
  while ((AdjList[i] -> point).label != input && i != 20) {
    i++;
  }
  if (i != 20) {
    AdjList[i] = NULL;
  }

  //Next remove all connections to that vertex:
  for (int j = 0; j < 20; j++) {
    if (AdjList[i] != NULL && AdjList[i] -> connections != NULL) {

      //remove edge from connections linked list
      edge* previous = NULL;
      edge* current = AdjList[i] -> connections;

      while (current != NULL && current -> point -> label != input) {
	previous = current;
	current = current -> next;
      }
      if (current != NULL && current == AdjList[i] -> connections) {
	AdjList[i] -> connections = current -> next;
      }
      else if (current != NULL) {
	previous -> next = current -> next;
      }
    }
  }
}

void graph::addEdge(char first, char second) {
}

void graph::remEdge(char first, char second) {
}

void graph::print() {
}

void graph::shortestPath(char first, char last) {
}
