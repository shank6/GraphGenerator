/***
****** Author : Shankar Kartik Jawahar
        Embedded Systems Lab,
        Northeastern University
******
    Random Graph Generator      v0.1
    Connected Classes - Node, Edge

*****
    Nodes - List is used so that instertions and deletions of Nodes can be made easy

****
 v0.2


***/


#ifndef GRAPHS_H
#define GRAPHS_H
#include "Edge.h"
#include "Node.h"
#include "SDFAnalysis.h"
#include <vector>
#include <list>
#include <cstdlib>
#include <string>
#include <time.h>
#include <iostream>
#include <fstream>




class Graphs : public SDFAnalysis
{
    public:
        Graphs();
        Graphs(uint e_num, uint n_num);
        ~Graphs();

        void printGraph();
        bool printGraph(const std::string filePath);
        void addNodestoGraph(Node &n);
        void addEdgestoGraph(Edge &e);
        void findandAddNodestoGraph(uint nodes_num);

        Node* findNode(std::vector<Node*>* node_list);
        Node* findNode(std::vector<Node*>* node_list , Node* );  // overload findNode to find a suitable node for a channel
        void  makeEdge(Node* n1, Node* n2);
         //   std::pair<uint, uint>* getsize();
        /* Builds the graph */
        bool buildGraphAllConnected(uint nodes_num, uint edges_num);
         //     bool buildGraph(uint nodes_num, uint edges_num);
        /* A routine to find the position of the node in the list */
        uint findNodePositionInList(Node* n, std::vector<Node*>* node_list);

        /*
        Graphs(const Graphs& other);
        Graphs& operator=(const Graphs& other);
        */
    protected:
        uint NodePositionBuffer;   // A variable that holds the node index in vector to be deleted from the copy
    private:

    uint num_Nodes;
    uint num_Edges;

    Node* firstNode;
    Node* lastNode;
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;


};

#endif // GRAPHS_Hfile:///home/artist/workspace/Graphgen/Grahpgen/src/Graphs.cpp

