//
// Created by clays on 11/23/2019.
//

#include "Hanoi.h"

Hanoi::Hanoi(int pegCount, int diskCount) {

    currentNode = Node();
    goalNode = Node();

    InitializeStart(pegCount, diskCount);
    InitializeGoal(pegCount, diskCount);

    brain = Ai(diskCount, currentNode);

    int i = 0;
    for (; !(currentNode == goalNode); ++i) {
        print("Itr: " + to_string(i));
        currentNode.print();
        currentNode = brain.ExpandNode(currentNode);
    }

    print("Itr: " + to_string(i));
    currentNode.print();

    brain.PrintConclusion();

}

void Hanoi::InitializeStart(int pegCount, int diskCount) {
    currentNode.pegs.emplace_back(diskCount, diskCount); //first peg with disks
    for (int i = 1; i < pegCount; ++i) {

        currentNode.pegs.emplace_back(0, pegCount); // all other empty startNode->pegs
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
    for (int i = 0; i < currentNode.pegs.size() ; ++i) {
        msg += "\n--------------\nPeg: " + to_string(i) + "\n";
        msg += "\n" + currentNode.pegs[i].ToString() + "\n";
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






