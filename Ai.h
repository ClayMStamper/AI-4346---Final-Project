//
// Created by clays on 11/23/2019.
//

#ifndef AI_PROJ2_AI_H
#define AI_PROJ2_AI_H

#include "Peg.h"
#include "map"

class Ai {

protected:
    int diskCount;

public:
    int G();
    int H(vector<Peg> pegs);
    virtual vector <Peg> ExpandNode (vector<vector<Peg>> pegsSets);

private:

};


#endif //AI_PROJ2_AI_H
