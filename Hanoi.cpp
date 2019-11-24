//
// Created by clays on 11/23/2019.
//

#include "Hanoi.h"

Hanoi::Hanoi(int pegCount, int diskCount) {
    currentState = Node();
    targetState = Node(
            {{Peg(0, diskCount)},
            {Peg(0, diskCount)},
            {Peg(diskCount, diskCount)}}
    );

    InitializeCurrent(pegCount, diskCount);
    print(currentState.ToString());
    print(GenerateNodes().ToString());
    brain = RBFS(diskCount);

}

void Hanoi::InitializeCurrent(int pegCount, int diskCount) {
    currentState.pegs.emplace_back(diskCount, diskCount); //first peg with disks
    for (int i = 1; i < pegCount; ++i) {
        currentState.pegs.emplace_back(0, pegCount); // all other empty currentState->pegs
    }
}

string Hanoi::ToString() {
    string msg;
    for (int i = 0; i < currentState.pegs.size() ; ++i) {
        msg += "\n--------------\nPeg: " + to_string(i) + "\n";
        msg += "\n" + currentState.pegs[i].ToString() + "\n";
    }
    return msg;
}

void Hanoi::print() {
    Debug::Log(ToString());
}

NodeSet Hanoi::GenerateNodes() {
    auto nodeSet = NodeSet();//set of possible currentState->pegs
    for (int i = 0; i < currentState.pegs.size(); ++i) { //go through each actual peg

        auto openNodes = GenerateNodes(i); //get possible sets of currentState->pegs if this peg's disk is moved
        for (int j = 0; j < openNodes.Size(); ++j) { //loop through possible sets from this move
            nodeSet.nodes.push_back(openNodes.nodes[j]); //add possible sets to "nodeSet"
        }

    }
    return nodeSet;
}

NodeSet Hanoi::GenerateNodes(int thisPeg) {

    auto nodeSet = NodeSet();

    for (int i = 0; i < currentState.pegs.size(); ++i) {
        if (thisPeg != i && CanMove(currentState.pegs[thisPeg], currentState.pegs[i])){
            auto tempPegs = currentState.pegs;
            Disk moveDisk = currentState.pegs[thisPeg].disks.back();
            tempPegs[thisPeg].disks.pop_back();
            tempPegs[i].disks.push_back(moveDisk);
            nodeSet.nodes.emplace_back(tempPegs);
        }
    }

    return nodeSet;
}

bool Hanoi::CanMove(Peg a, Peg b) {

    if (a.disks.empty())
        return false;
    if (b.disks.empty())
        return true;
    return (a.disks.back().width < b.disks.back().width);

}






