#ifndef EDGE_H
#define EDGE_H
#include "Node.h"
#include <string>
#include <utility>
#include <sstream>



class Edge : public Node
{
    public:
        Edge(std::string label1 , std::string tail, std::string head, Node n1, Node n2);
        virtual ~Edge();

        void printEdge(int X, std::ofstream* Obj);

    //    Edge(const Edge& other);
    Edge& operator=(const Edge& other);
    protected:
    private:
    std::string label;
    std::string taillabel;
    std::string headlabel;
    Node head, tail;
        ///std::pair <Node, Node> node_pair;





};

#endif // EDGE_H
