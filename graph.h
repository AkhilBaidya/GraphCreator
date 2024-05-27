/*The graph class*/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstring>

using namespace std;

struct vertex {
  char label;
};

struct edge {
  vertex* to;
  int weight;
  edge* next;
};

struct location {
  int visited;
  vertex point;
  edge* connections;
};

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
