#include <iostream>
#include <cstring>
#include "graph.h"

using namespace std;

int main() {

  bool running = true;
  char command[10];
  graph* data = new graph();

  while (running) {
    cout << "What would you like to do? addvertex, addedge, remvertex, remedge, print, getpath" << endl;
    cin >> command;
    if (!strcmp(command, "addvertex")) {
      cout << "enter vertex name" << endl;
      char answer;
      cin >> answer;

      data -> addVertex(answer);
    }
    else if (!strcmp(command, "addedge")) {
      char from;
      char to;
      int weight;
      cout << "from where?" << endl;
      cin >> from;
      cout << "to where?" << endl;
      cin >> to;
      cout << "of what weight?" << endl;
      cin >> weight;

      data -> addEdge(from, to, weight);
      
    }
    else if (!strcmp(command, "remvertex")) {
      cout << "enter vertex name" << endl;
      char answer;
      cin >> answer;

      data -> remVertex(answer);
    }
    else if (!strcmp(command, "remedge")) {
      char from;
      char to;
      cout << "from where?" << endl;
      cin >> from;
      cout << "to where?" << endl;
      cin >> to;
    
      data -> remEdge(from, to);
      
    }
    else if (!strcmp(command, "print")) {
      data -> print();
    }

    else if (!strcmp(command, "quit")) {
      running = false;
      cout << "Quitting!" << endl;
    }

    else if (!strcmp(command, "getpath")) {
      char from;
      char to;
      cout << "from where?" << endl;
      cin >> from;
      cout << "to where?" << endl;
      cin >> to;
    
      data -> shortestPath(from, to);
   
    }
  }
  return 0;
}
