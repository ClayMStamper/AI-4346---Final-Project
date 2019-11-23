//
// Created by clays on 11/23/2019.
//

#ifndef AI_PROJ2_ASTAR_H
#define AI_PROJ2_ASTAR_H

#include "Ai.h"

class AStar : public Ai {

private:

public:
    vector <Peg> ExpandNode (vector<vector<Peg>> pegsSets) override;

private:

};


#endif //AI_PROJ2_ASTAR_H
