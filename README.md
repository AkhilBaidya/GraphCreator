# GraphCreator
A directed graph with vertices that can be connected by edges (edges travel in a single direction). Can find the shortest path between two vertices!

# Set-Up
The code can be compiled in this manner. For some final .exe file "graphCreator":

g++ -o graphCreator graph.cpp playground.cpp

Then run "./graphCreator" to start the application.

# How to Use + Cautions
There are 7 commands that can be used to interact with the graph (commands are all case-sensitive and should be entered in lowercase):

1. There is "mkvertex."

Input this command and a vertex name to create a vertex. Vertex names need to be unique from existing vertices' names. Additionally, they are restricted to being one character, such as 'a.'

2. There is "mkedge."

Input this command and the name of two vertices (a "to" and "from" vertex) to create an edge from the first vertex to the second. The program will also ask you to input a weight for the edge. Please input a non-negative integer. The program also expresses infinite distance (total disconnection between vertices) as 9999, so keep the max sum of edges in a path in the graph less than 9999. 

3. There is "rmvertex."

Input this command and the name of a vertex to delete that vertex.

4. There is "rmedge."

Input this command the names of two vertices to delete the edge traveling from the first vertex to the second.

5. There is "print."

Input this command to print out the graph as a list of vertices, each with a list of connections, and as an adjacency table.

6. There is "getshortestpath."

Input this command the name of two vertices to print out the shortest path (least sum of edge weights) from the first vertex to the second.

7. There is "quit."

This ends the program.

# Sources
Refer to heading comments in the individual files in this repository.
