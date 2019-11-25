//
// Created by clays on 11/23/2019.
//

#ifndef AI_PROJ2_HANOI_H
#define AI_PROJ2_HANOI_H


#include <utility>
#include <vector>
#include "AStar.h"
#include "RBFS.h"

using namespace std;

class Hanoi : public IConvertToString {

private: //private fields
    Node currentNode;
    Node goalNode;
   // Ai brain = Ai(3, Node());

public: // public methods
    Hanoi() = default;
    Hanoi(int pegCount);
    ~Hanoi() = default;
    string ToString() override;

private: // private methods
    void InitializeStart(int pegCount, int diskCount);
    void InitializeGoal(int pegCount, int diskCount);
    bool CanMove(Peg a, Peg b);

};


#endif //AI_PROJ2_HANOI_H
