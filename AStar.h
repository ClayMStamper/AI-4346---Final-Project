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
    Node ExpandNode (NodeSet pegsSets) override;

private:

};


#endif //AI_PROJ2_ASTAR_H
