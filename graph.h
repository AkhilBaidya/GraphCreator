/*The graph class*/

#include <iostream>
#include <cstring>

using namespace std;

struct vertex {
  char label;
};

struct edge {
  vertex* to;
  int weight;
};

