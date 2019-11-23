//
// Created by clays on 11/23/2019.
//

#ifndef AI_PROJ2_HANOI_H
#define AI_PROJ2_HANOI_H


#include <vector>
#include "Debug.h"
#include "Peg.h"
#include "RBFS.h"

using namespace std;

class Hanoi : public IConvertToString {

private: //private fields
    vector<Peg> pegs;
    RBFS brain = RBFS();

public: // public methods
    Hanoi(int pegCount, int diskCount);
    ~Hanoi() = default;
    string ToString() override;

private: // private methods
    void InitializePegs(int pegCount, int diskCount);
    void Print(); //print this object
    void Print(string msg) {Debug::Log(msg);} //print some message
    vector<vector<Peg>> GenerateNodes();
    vector<vector<Peg>> GenerateNodes(int thisPeg);
    bool CanMove(Peg a, Peg b);

};


#endif //AI_PROJ2_HANOI_H
