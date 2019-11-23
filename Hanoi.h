//
// Created by clays on 11/23/2019.
//

#ifndef AI_PROJ2_HANOI_H
#define AI_PROJ2_HANOI_H


#include <vector>
#include "Debug.h"
#include "Peg.h"

using namespace std;

class Hanoi : public IConvertToString {

private: //private fields
    vector<Peg> pegs;

public: // public methods
    Hanoi(int pegCount, int diskCount);
    string ToString() override;

private: // private methods
    void InitializePegs(int pegCount, int diskCount);
    void RenderFrame();
    vector<Peg>* GenerateNodes();


};


#endif //AI_PROJ2_HANOI_H
