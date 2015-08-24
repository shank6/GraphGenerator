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

#define MAX_NODES   8
#define MIN_NODES   5
#define MAX_EDGES   2*MAX_NODES

using namespace std;

int main()
{

    cout << "Random graph Generator" << endl;
    Node::buildDataBase(26*16);
//    Node::printDataBase();
    srand(time(NULL));
    uint Nodes = (rand() % MAX_NODES )+ MIN_NODES;
    //uint temp =  (rand() % MAX_EDGES );
    uint Edges = (rand() % MAX_EDGES )+ Nodes - 1;

//    cout<< "NODES : " << Nodes << " Edges : " << temp << "  " << Edges << endl;
  Graphs g1;
  g1.buildGraphAllConnected(Nodes, Edges);
  g1.printGraph();
  g1.printGraph("graph");


    return 0;
}
