//
// Created by clays on 11/23/2019.
//

#ifndef AI_PROJ2_ASTAR_H
#define AI_PROJ2_ASTAR_H

#include "Ai.h"

class AStar : public Ai {

private:
    int G(Node actual);
    string name = "A*";

public:
    AStar() = default;
    AStar(int diskCount, Node startNode, Node goalNode);
    ~AStar() = default;
    Node ExpandNode(Node n) override;
    void PrintConclusion() override;

private:

};


#endif //AI_PROJ2_ASTAR_H
