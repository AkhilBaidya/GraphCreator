/*Graph Creator Playground - Akhil Baidya

Date of Submission: 5/31/24

Notes: In this file, the user can create a graph and interact with it using several commands such as "mkvertex," "mkedge," "rmvertex," "rmedge," "print," "getshortestpath," and "quit."

Manual: Refer to README file
 */

#include <iostream>
#include <cstring>
#include "graph.h"

using namespace std;

int main() {

  //SET-UP:
  bool running = true; //this loops the command-entry
  char command[20]; //this will store user commands
  graph* data = new graph(); //create an empty graph

  cout << "Welcome to Graph Creator Ver. 1" << endl;
  
  //MAIN LOOP:
  while (running) {
    cout << "What would you like to do? (Options: mkvertex, mkedge, rmvertex, rmedge, print, getshortestpath, quit)" << endl;
    cin >> command; //get user's command

    //Adding a vertex:
    if (!strcmp(command, "mkvertex")) {
      cout << "Please enter vertex name (single character, unique from other vertices): " << endl;
      char answer;
      cin >> answer; //read in vertex name
      
      data -> addVertex(answer); //create vertex
    }

    //Adding an edge:
    else if (!strcmp(command, "mkedge")) {
      char from;
      char to;
      int weight; //data to collect

      //Get data:
      cout << "From where? (give vertex name)" << endl;
      cin >> from;
      cout << "To where? (give vertex name)" << endl;
      cin >> to;
      cout << "Of what weight? (enter an integer, make sure that max sum of edges in graph is under 9999)" << endl;
      cin >> weight;

      data -> addEdge(from, to, weight); //create edge    
    }

    //Removing a vertex:
    else if (!strcmp(command, "rmvertex")) {
      cout << "Please enter vertex name: " << endl;
      char answer;
      cin >> answer; //read in vertex name

      data -> remVertex(answer); //remove vertex
    }

    //Removing an edge:
    else if (!strcmp(command, "rmedge")) {
      char from;
      char to;

      //Get data:
      cout << "From where? (give vertex name)" << endl;
      cin >> from;
      cout << "To where? (give vertex name)" << endl;
      cin >> to;
    
      data -> remEdge(from, to); //remove edge
      
    }

    //Print graph as table:
    else if (!strcmp(command, "print")) {
      data -> print();
    }

    //Quit program:
    else if (!strcmp(command, "quit")) {
      running = false; //end loop
      cout << "Quitting!" << endl;
    }

    //Print shortest path between two vertices:
    else if (!strcmp(command, "getshortestpath")) {
      char from;
      char to;

      //Get data:
      cout << "From where? (give vertex name)" << endl;
      cin >> from;
      cout << "To where? (give vertex name)" << endl;
      cin >> to;

      cout << from;
      cout << to;
      data -> shortestPath(from, to); //get shortest path
    }
  }
  return 0;
}
