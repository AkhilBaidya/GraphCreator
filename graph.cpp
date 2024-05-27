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

  while (AdjList[i] != NULL && i != 20) {
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
  while (AdjList[i] != NULL && (AdjList[i] -> point).label != input && i != 20) {
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

void graph::addEdge(char first, char second, int input) {
  //First check if first is in table and get its index
  int i = 0;
  int firstIndex;
  while (AdjList[i] != NULL && AdjList[i] -> point != first && i != 20) {
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
  int secIndex;
  while (AdjList[i] != NULL && AdjList[i] -> point != second && i != 20) {
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
  edge* toSecond;
  toSecond -> to = &(AdjList[firstIndex] -> point);
  toSecond -> weight = input;
  
  edge* current1 = AdjList[firstIndex] -> connections;
  if (current1 == NULL) {
    AdjList[firstIndex] -> connections = toSecond;
  }
  else {
    while (current1 -> next != NULL) {
      current1 = current1 -> next;
    }

    current1 -> next = toSecond;
  }
  
  //Now, if both exist, update connection on the second
  edge* toFirst;
  toFirst -> to = &(AdjList[secIndex] -> point);
  toFirst -> weight = input;
  
  edge* current2 = AdjList[secIndex] -> connections;
  if (current2 == NULL) {
    AdjList[secIndex] -> connections = toFirst;
  }
  else {
    while (current2 -> next != NULL) {
      current2 = current2 -> next;
    }

    current2 -> next = toFirst;
  }

  return;
}

void graph::remEdge(char first, char second) {
  //First check if first is in table and get its index
  int i = 0;
  int firstIndex;
  while (AdjList[i] != NULL && AdjList[i] -> point != first && i != 20) {
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
  int secIndex;
  while (AdjList[i] != NULL && AdjList[i] -> point != second && i != 20) {
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
  }
  return;
}

void graph::print() {
}

void graph::shortestPath(char first, char last) {
}
