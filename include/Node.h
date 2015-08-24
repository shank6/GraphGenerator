/***
****** Author : Shankar Kartik Jawahar
        Embedded Systems Lab,
        Northeastern University
******
    Random Graph Generator v0.1
    Node Program
    Connected Classes - Edge, Graph
    Node - label
*****

    v0.2

    Node format - label , inputType, outputType
    InEdge, OutEdge, degree
*** Modifications **************
    Node() - constructor
    Node Database - Contains all Node Types (From "a_1_1 to z_32_32")



***/



#ifndef NODE_H
#define NODE_H
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>




class Node
{
    public:
        enum print_t { file, console};



        Node();
        Node(std::string label1, uint input, uint output );
        virtual ~Node();


        void printNode(int Type, std::ofstream* obj);
        std::string getLabel();
        uint getInputType();
        uint getOutputType();

/*
        Node(const Node& other);
*/
        Node& operator=(const Node& other);
        print_t printType;

/* STatic Database for the pool of Nodes
* And the tools to build it
*/
        static std::vector<Node*> NodeDataBase;
        static  bool buildDataBase(uint nodes_num);
        static void printDataBase();
        static void printNodesinDataBase(std::vector<Node*>* NodeList);

    protected:
        std::string label;

    private:
        uint inputType;
        uint outputType;
        int degree;
        uint InEdge;
        uint OutEdge;

        static const std::string labelArray;
        static const uint ioArray[4];


};

#endif // NODE_H
