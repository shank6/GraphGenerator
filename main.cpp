/***
****** Author : Shankar Kartik Jawahar
        Embedded Systems Lab,
        Northeastern University
******
    Random Graph Generator v0.1
    Main Program
    Connected Classes - Node, Edge, Graph

*****

***/





#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Graphs.h"
#include "time.h"

#define MAX_NODES   7
#define MAX_EDGES   10

using namespace std;

int main()
{

    cout << "Random graph Generator" << endl;
    srand(time(NULL));
    uint Nodes = rand() % MAX_NODES + 1;
    uint Edges = MAX_EDGES;

    cout<< "NODES : " << Nodes << " Edges : " << Edges << endl;
    Graphs g1;
    g1.buildGraph(Nodes, MAX_EDGES);
    g1.printGraph();
    g1.printGraph("graph");

    return 0;
}
