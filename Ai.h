//
// Created by clays on 11/23/2019.
//

#ifndef AI_PROJ2_AI_H
#define AI_PROJ2_AI_H

#include "Peg.h"
#include "map"
#include "NodeSet.h"

class Ai {

protected:
    int diskCount;

public:
    int G();
    int H(Node pegs);
    virtual Node ExpandNode (NodeSet pegsSets);

private:

};


#endif //AI_PROJ2_AI_H
