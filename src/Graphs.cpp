#include "Graphs.h"

Graphs::Graphs()
{
    num_Edges = 0;
    num_Nodes = 0;
    srand(time(NULL));  //seed the rand()
}

// overloading constructor
Graphs::Graphs(uint edges_num = 0, uint nodes_num = 0)

{
    num_Edges = edges_num;
    num_Nodes = nodes_num;
    srand(time(NULL));
}

/* Returns the size of the graph */
// A pair of number of nodes and edges is returned
/*
std::pair<uint, uint>* Graphs::getsize()
{
    num_Edges = edges.size();
    num_Edges = nodes.size();
    std::pair<uint, uint> gSize = std::make_pair(num_Nodes, num_Edges);
    return &gSize;

}

*/

/* Prints the Graph */
void Graphs::printGraph()
{

  //  Graphs G1 = *this;

    std::cout << "digraph" << std::endl << "{" << std::endl;

    std::cout << "size\"" << num_Nodes << "," << num_Edges << "\";" << std::endl;
    /* Print the nodes in the graph */
    std::ofstream O;
    for(std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
    {
        (*it)->printNode(1, &O);
    }

    std::cout << std::endl;


    /* Print the edges in the graph */

    for(std::vector<Edge*>::iterator it = edges.begin(); it!= edges.end(); it++)
    {
        (*it)->printEdge(1, NULL);
    }

    std::cout << "}" << std::endl;
}



void Graphs::addNodestoGraph(Node &n)
{

    nodes.push_back(new Node(n));
    num_Nodes = nodes.size();
}

void Graphs::addEdgestoGraph(Edge &e)
{
    edges.push_back(new Edge(e));
    num_Edges = edges.size();
}

/* Find random Nodes */
Node* Graphs::findNode(std::vector<Node*>* node_list = NULL)
{

    int x = rand() % num_Nodes + 1;

    if(node_list->at(x-1))
    {
        return node_list->at(x-1);
    }
    return NULL;

}

/* Make random edges */
void Graphs::makeEdge(Node* n1 = NULL,  Node* n2 = NULL)
{

    bool debug = false;

    n1 = findNode(&nodes);
    n2 = findNode(&nodes);



    //const std::string edge_label = "ch" + std::to_string(num_Edges + 1);
    std::stringstream ss;
    ss << "ch" << (num_Edges+1);

    const std::string edge_channel = ss.str();
    const std::string edge_head_label = "1";
    const std::string edge_tail_label = "1";
    Edge e(edge_channel, edge_head_label, edge_tail_label, *n1, *n2);
    addEdgestoGraph(e);

    if(debug)
    {
        std::cout << " Debug Mode : makeEdge() \n" ;
        std::cout << "Edges number : " << num_Edges << std::endl;
        std::cout << n1->getLabel() << " " << n2->getLabel()<< " are the nodes found " << std::endl;
    }
}


bool Graphs::buildGraph(uint nodes_num, uint edges_num)
{
    bool debug = false;


    for(int i = 1; i <= nodes_num; i++)
    {
        std::stringstream ss;
        ss << "a" << i;
        Node n(ss.str());
        addNodestoGraph(n);

    }

    for(int i = 1; i <= edges_num; i++)
    {
        makeEdge();
    }


    if(debug)
    {
         std::cout << "nodes " << nodes.size() << "  with edges " << edges.size() << std::endl;

        std::ofstream* Obj;
         for(std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
        {
            (*it)->printNode(1, Obj);
        }


        for(std::vector<Edge*>::iterator it = edges.begin(); it!= edges.end(); it++)
        {
            (*it)->printEdge(1, Obj);
        }

    }


    return 1;
}

/* Prints the Graph to file*/
bool Graphs::printGraph(const std::string filePath)
{

  //  Graphs G1 = *this;
    std::ofstream file1;
    file1.open(filePath.c_str());


    file1 << "digraph g "  << "{" << std::endl;

    file1 << "size\"" << num_Nodes << "," << num_Edges << "\";" << std::endl;
    /* Print the nodes in the graph */

    for(std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
    {
        (*it)->printNode(0, &file1);
    }

    file1 << std::endl;


    /* Print the edges in the graph */

    for(std::vector<Edge*>::iterator it = edges.begin(); it!= edges.end(); it++)
    {
        (*it)->printEdge(0, &file1);
    }

    file1 << "}" << std::endl;
    file1.close();

    return true;
}


Graphs::~Graphs()
{
    //dtor
}

/* Build A Graph with all nodes connected */

bool Graphs::buildGraphAllConnected(uint nodes_num, uint edges_num)
{
    bool debug = false;
/*
    // Check for the exceptions
    if(edges_num <= nodes_num)
    {
        throw ;
    }
*/
    if(edges_num <= nodes_num-1)
    {
        std::cerr << " Not enough edges" << std::endl;
        return false;
    }

     for(int i = 1; i <= nodes_num; i++)
     {
        std::stringstream ss;
        ss << "a" << i;
        Node n(ss.str());
        addNodestoGraph(n);

     }


    // To ensure all nodes are connected

    std::vector<Node*> NodeCopy = nodes;

    for(int i = 1; i <= num_Nodes - 1;  i++)
    {
        Node* n1 = findNode(&NodeCopy);
        Node* n2 = findNode(&NodeCopy);
        makeEdge(n1, n2);


// ON PROGRESS - find the position and remove it

    }



    uint netEdges = edges_num - nodes_num - 1;
    for(int i = 1; i <= netEdges;  i++)
    {
        makeEdge();
    }



    return true;
}

/*
Graphs::Graphs(const Graphs& other)
{
    //copy ctor
}

Graphs& Graphs::operator=(const Graphs& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

*/
