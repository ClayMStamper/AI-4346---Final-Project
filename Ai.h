//
// Created by clays on 11/23/2019.
//

#ifndef AI_PROJ2_AI_H
#define AI_PROJ2_AI_H

#include "cstdlib"
#include "map"
#include "Debug.h"
#include "Peg.h"
#include "NodeSet.h"
#include "chrono"

using namespace std::chrono;

class Ai : public IConvertToString {

protected:
    string delim = ",";
    int diskCount = 3;
    Node startNode;
    int expanded = 0, generated = 0;
    high_resolution_clock::time_point start, stop;
    double timeDuration;

public:
    NodeSet openStack = NodeSet({});
    NodeSet closedStack = NodeSet({});
    string resultString;

public:
    Ai() = default;
    Ai(int diskCount, Node currentNode, Node goalNode);
    ~Ai() = default;
    int G();
    int H(Node actual);
    virtual Node ExpandNode(Node n);
    string ToString() override;
    void GenerateNodes(Node n);
    bool CanMove(Peg a, Peg b);
    void PrintConclusion();

private:

};


#endif //AI_PROJ2_AI_H
