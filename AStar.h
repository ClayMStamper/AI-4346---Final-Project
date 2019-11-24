//
// Created by clays on 11/23/2019.
//

#ifndef AI_PROJ2_ASTAR_H
#define AI_PROJ2_ASTAR_H

#include "Ai.h"
#include "NodeSet.h"

class AStar : public Ai {

private:

public:
    AStar() {}

    Node ExpandNode(Node n) override;

private:

};


#endif //AI_PROJ2_ASTAR_H
