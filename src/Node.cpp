#include "Node.h"

const std::string Node::labelArray ="abcdefghijklmnopqrstuvwxyz";
const uint Node::ioArray[4] = {1, 8, 16, 32};
std::vector<Node*> Node::NodeDataBase;
Node::Node()
{

}

Node::Node(std::string label1 , uint input = 0, uint output = 0)
: label(label1), inputType(input) , outputType(output)
{
}

Node::~Node()
{

    //dtor
}

/* To get the label */
/* Called from the node object */
std::string Node::getLabel()
{
    return label;
}


/*To get Input Type */

uint Node::getInputType()
{
    return inputType;
}


/*TO get Output Type */

uint Node::getOutputType()
{
    return outputType;
}


/* Prints the node */
/* Called from the node object */
void Node::printNode(int printType, std::ofstream* obj)
{
    //  a0 [ label="a0" ];
    std::stringstream ss;
    ss << this->getLabel() << " [ label= \"" << this->getLabel() <<  "\" ];" << std::endl;

    if(printType == 1)
        std::cout << ss.str();
    else
        {
            *obj << ss.str();
        }
}


/* Builds the entire database of Nodes */
bool Node::buildDataBase(uint nodes_number)
{
    for(uint i = 0; i < nodes_number/16; i++)
    {
        for(uint j = 0; j < 4; j++)
        for(uint k = 0; k < 4; k++)
        {
            std::stringstream ss;
            ss << Node::labelArray.substr(i, 1) << "_"  << Node::ioArray[j] << "_" << Node::ioArray[k] ;


            Node n(ss.str(), Node::ioArray[j], Node::ioArray[k]);
            Node::NodeDataBase.push_back(new Node(n));
        }
    }

    return true;
}


/* Reference Funtion to print out the entire node database */
void Node::printNodesinDataBase(std::vector<Node*>* NodeList)
{
    uint i = 1;
    for(std::vector<Node*>::iterator it = NodeList->begin(); it!= NodeList->end(); it++)
    {

        std::stringstream ss;
        ss << " Node " << i++ << " : " << (*it)->getLabel()  << " ip : " << (*it)->getInputType()
        << "   op : " << (*it)->getOutputType();
        std::cout << ss.str() << std::endl;
    }
}

void Node::printDataBase()
{

    Node::printNodesinDataBase(&Node::NodeDataBase);
    return;
}


Node& Node::operator=(const Node& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
