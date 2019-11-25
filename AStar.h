//
// Created by clays on 11/23/2019.
//

#ifndef AI_PROJ2_ASTAR_H
#define AI_PROJ2_ASTAR_H

#include "Ai.h"

class AStar : public Ai {

private:

public:
    AStar() = default;
    AStar(int diskCount, Node startNode);
    ~AStar() = default;
    Node ExpandNode(Node n) override;

private:

};


#endif //AI_PROJ2_ASTAR_H
