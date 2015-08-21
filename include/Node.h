#ifndef NODE_H
#define NODE_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>




class Node
{
    public:
        Node();
        Node(std::string label1);
        virtual ~Node();
         enum print_t { file, console};
        void printNode(int Type, std::ofstream* obj);
        std::string getLabel();
/*
        Node(const Node& other);
  */
        Node& operator=(const Node& other);
        print_t printType;
    protected:
    std::string label;

    private:


};

#endif // NODE_H
