#ifndef SDFANALYSIS_H
#define SDFANALYSIS_H
#include <vector>
#include "Node.h"
#include "Edge.h"


class SDFAnalysis
{
    public:
        SDFAnalysis();

        bool checkStartAndStop();
        bool checkNodeTypeConsistency(std::vector<Node*>* node_list);
       // Finds atleast one node inbetween 1st and last node of suitable type
        virtual ~SDFAnalysis();
    protected:
    private:
};

#endif // SDFANALYSIS_H
