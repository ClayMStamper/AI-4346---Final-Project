//
// Created by clays on 11/23/2019.
//

#include "Hanoi.h"

Hanoi::Hanoi(int pegCount, int diskCount) {

    startNode = Node();
    goalNode = Node();

    InitializeStart(pegCount, diskCount);
    InitializeGoal(pegCount, diskCount);

    brain = Ai(diskCount, startNode);
    //brain.ExpandNode(Node());
    //brain.openStack.print();

}

void Hanoi::InitializeStart(int pegCount, int diskCount) {
    startNode.pegs.emplace_back(diskCount, diskCount); //first peg with disks
    for (int i = 1; i < pegCount; ++i) {

        startNode.pegs.emplace_back(0, pegCount); // all other empty startNode->pegs
    }
}

void Hanoi::InitializeGoal(int pegCount, int diskCount) {
    for (int i = 0; i < pegCount - 1; ++i) {
        goalNode.pegs.emplace_back(0, pegCount); // all other empty startNode->pegs
    }
    goalNode.pegs.emplace_back(diskCount, diskCount); //first peg with disks
}

string Hanoi::ToString() {
    string msg;
    for (int i = 0; i < startNode.pegs.size() ; ++i) {
        msg += "\n--------------\nPeg: " + to_string(i) + "\n";
        msg += "\n" + startNode.pegs[i].ToString() + "\n";
    }
    return msg;
}

bool Hanoi::CanMove(Peg a, Peg b) {

    if (a.disks.empty())
        return false;
    if (b.disks.empty())
        return true;
    return (a.disks.back().width < b.disks.back().width);

}






