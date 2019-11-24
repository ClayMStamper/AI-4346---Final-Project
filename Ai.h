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

class Ai : public IConvertToString {

protected:
    int diskCount = 3;
    Node startNode;

public:
    NodeSet openStack = NodeSet({});
    NodeSet closedStack = NodeSet({});

public:
    Ai() = default;
    Ai(int diskCount, Node startNode);
    ~Ai() = default;
    int G();
    int H(Node actual);
    virtual Node ExpandNode(Node n);
    string ToString() override;
    void GenerateNodes(Node n);
    bool CanMove(Peg a, Peg b);

private:

};


#endif //AI_PROJ2_AI_H
