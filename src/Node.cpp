#include "Node.h"

Node::Node()
{

}

Node::Node(std::string label1 = NULL)
: label(label1)
{
}

Node::~Node()
{
    //dtor
}

/* Prints the node */
/* Called from the node object */
void Node::printNode(int printType, std::ofstream* obj)
{
    //  a0 [ label="a0" ];
    std::stringstream ss;
    ss << this->getLabel() << " [ label= \"" <<  this->getLabel() << "\" ];" << std::endl;

    if(printType == 1)
        std::cout << ss.str();
    else
        {
            *obj << ss.str();
        }
}


/* To get the label */
/* Called from the node object */
std::string Node::getLabel()
{
    return label;
}


Node& Node::operator=(const Node& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
