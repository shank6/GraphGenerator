#include "Edge.h"
#include <string>

Edge::Edge(std::string label , std::string taillabel, std::string headlabel, Node n1 , Node n2)
:
label(label),
taillabel(taillabel),
headlabel(headlabel),
head(n1),
tail(n2)
{

/*
   this->node_pair = std::make_pair(n1, n2);
   Node nn = this->node_pair.first;

   std::cout << "===== ";
   n1.printNode();
   //node_pair.first.printNode();


   std::cout << "===== ";
*/

}


Edge::~Edge()
{
    //dtor
}

/* Prints the edge in the required format */
/* Called from the edge object */

void Edge::printEdge(int printType, std::ofstream* obj)
{
    //a1 -> a0 [ label="ch0", taillabel="1", headlabel="1" ];
    Edge e1 = *this;

    std::stringstream ss;
   /*
    Node n1 = e1.node_pair.first;
    Node n2 = e1.node_pair.second;
*/


   ss << e1.head.getLabel() << " -> " << e1.tail.getLabel() << " [ label=\"" << e1.label <<  "\", taillabel=\"" << e1.taillabel
   << "\", headlabel=\"" << e1.headlabel << "\" ];" << std::endl ;

    if(printType == 1)
        std::cout << ss.str();
    else if(printType == 0)
    {
       *obj << ss.str();
    }
}

/*

Edge::Edge(const Edge& other)
{
    //copy ctor

}

*/

Edge& Edge::operator=(const Edge& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    //assignment operator
    return *this;
}
