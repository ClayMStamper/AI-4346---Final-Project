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
    int diskCount;

public:
    int G();
    int H(Node actual);
    virtual Node ExpandNode (NodeSet nodeSet, Node goal);
    string ToString() override;

private:

};


#endif //AI_PROJ2_AI_H
