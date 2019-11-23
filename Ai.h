//
// Created by clays on 11/23/2019.
//

#ifndef AI_PROJ2_AI_H
#define AI_PROJ2_AI_H

#include "Peg.h"

class Ai {

protected:
    int diskCount;

public:
    int G();
    int H();
    virtual vector <Peg>* ExpandNode (vector<Peg>* pegs);

private:

};


#endif //AI_PROJ2_AI_H
