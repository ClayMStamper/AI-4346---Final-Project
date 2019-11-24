//
// Created by clays on 11/23/2019.
//

#ifndef AI_PROJ2_HANOI_H
#define AI_PROJ2_HANOI_H


#include <utility>
#include <vector>
#include "Debug.h"
#include "Peg.h"
#include "RBFS.h"
#include "NodeSet.h"

using namespace std;

class Hanoi : public IConvertToString {

private: //private fields
    Node currentState;
    Node targetState;
    RBFS brain = RBFS();

public: // public methods
    Hanoi() = default;
    Hanoi(int pegCount, int diskCount);
    ~Hanoi() = default;
    string ToString() override;

private: // private methods
    void InitializeCurrent(int pegCount, int diskCount);
    void InitializeTarget(int pegCount, int diskCount);
    void print(); //print this object
    static void print(string msg) {Debug::Log(std::move(msg));} //print some message
    NodeSet GenerateNodes();
    NodeSet GenerateNodes(int thisPeg);
    bool CanMove(Peg a, Peg b);

};


#endif //AI_PROJ2_HANOI_H
