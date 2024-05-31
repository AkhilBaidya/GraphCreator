/* Graph Class Header - Akhil Baidya

Date of Submission: 5/31/24

Notes: This file lists the functions and variables inside the Graph Class (such as the adjacency list and functions to add/remove vertices and edges, print the list, and give the shortest path between two vertices)

It also defines the structs for the vertices, edges, and locations (a struct containing vertices and their connections).

Sources: 
For the syntax of a header guard, I referred to https://www.learncpp.com/cpp-tutorial/header-guards/, the tutorial on learncpp.com by the user Alex. 
*/

//Header Guard:
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstring>

using namespace std;

//Vertex:
struct vertex {
  char label; //has name
};

//Edge:
struct edge {
  vertex* to; //points somewhere (directed graph so is not bi-directional)
  int weight; //value
  edge* next; //will put edges in linked list of connections
};

//Location:
struct location {
  int visited; //tells whether vertex has been visited
  vertex point; //contains vertex
  edge* connections; //contains edges from vertex
};

//Actual Class:
class graph {

 public:
  graph(); //constructor
  ~graph(); //destructor
  void addVertex(char input); //add vertex
  void remVertex(char input); //delete vertex
  void addEdge(char first, char second, int input); //add edge
  void remEdge(char first, char second); //delete edge
  void print(); //print out adjacency list
  void shortestPath(char first, char last);
  
 private:
  location* AdjList[20]; //adjacency list
};

#endif
