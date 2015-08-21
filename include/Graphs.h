/***
****** Author : Shankar Kartik Jawahar
        Embedded Systems Lab,
        Northeastern University
******
    Random Graph Generator      v0.1
    Connected Classes - Node, Edge

*****
    Nodes - List is used so that instertions and deletions of Nodes can be made easy
    Edge -
***/


#ifndef GRAPHS_H
#define GRAPHS_H
#include "Edge.h"
#include "Node.h"
#include <vector>
#include <list>
#include <cstdlib>
#include <string>
#include <time.h>
#include <iostream>
#include <fstream>




class Graphs
{
    public:
        Graphs();
        Graphs(uint e_num, uint n_num);
        ~Graphs();

        void printGraph();
        bool printGraph(const std::string filePath);
        void addNodestoGraph(Node &n);
        void addEdgestoGraph(Edge &e);
     //   std::pair<uint, uint>* getsize();
        Node* findNode(std::vector<Node*>* node_list);
        void  makeEdge(Node* n1, Node* n2);
        bool buildGraph(uint nodes_num, uint edges_num);
        bool buildGraphAllConnected(uint nodes_num, uint edges_num);
        /*
        Graphs(const Graphs& other);
        Graphs& operator=(const Graphs& other);
        */
    protected:
    private:

    uint num_Nodes;
    uint num_Edges;

   std::vector<Node*> nodes;
   std::vector<Edge*> edges;


};

#endif // GRAPHS_Hfile:///home/artist/workspace/Graphgen/Grahpgen/src/Graphs.cpp

