//
// Created by clays on 11/23/2019.
//

#include "Hanoi.h"

Hanoi::Hanoi(int pegCount, int diskCount) {

    InitializePegs(pegCount, diskCount);
    vector<Peg>* pegsPtr = &pegs;
    brain = RBFS(diskCount);
    pegs = brain.ExpandNode(GenerateNodes());
    Print(GenerateNodes());

}

void Hanoi::InitializePegs(int pegCount, int diskCount) {
    pegs.emplace_back(diskCount, diskCount); //first peg with disks
    for (int i = 1; i < pegCount; ++i) {
        pegs.emplace_back(0, pegCount); // all other empty pegs
    }
}

string Hanoi::ToString() {
    string msg;
    for (int i = 0; i < pegs.size() ; ++i) {
        msg += "\n--------------\nPeg: " + to_string(i) + "\n";
        msg += "\n" + pegs[i].ToString() + "\n";
    }
    return msg;
}

void Hanoi::Print() {
    Debug::Log(ToString());
}

vector<vector<Peg>> Hanoi::GenerateNodes() {
    auto nodes =  vector<vector<Peg>>{pegs}; //set of possible pegs
    for (int i = 0; i < pegs.size(); ++i) { //go through each actual peg

        auto possiblePegSet = GenerateNodes(i); //get possible sets of pegs if this peg's disk is moved
        for (int j = 0; j < possiblePegSet.size(); ++j) { //loop through possible sets from this move
            nodes.push_back(possiblePegSet[j]); //add possible sets to "nodes"
        }

    }
    return nodes;
}

vector<vector<Peg>> Hanoi::GenerateNodes(int thisPeg) {

    auto nodes = vector<vector<Peg>>();

    for (int i = 0; i < pegs.size(); ++i) {
        if (thisPeg != i && CanMove(pegs[thisPeg], pegs[i])){
            auto tempPegs = pegs;
            Disk moveDisk = pegs[thisPeg].disks.back();
            tempPegs[thisPeg].disks.pop_back();
            tempPegs[i].disks.push_back(moveDisk);
            nodes.push_back(tempPegs);
        }
    }

    return nodes;
}

bool Hanoi::CanMove(Peg a, Peg b) {

    if (a.disks.empty())
        return false;
    if (b.disks.empty())
        return true;
    return (a.disks.back().width < b.disks.back().width);

}

void Hanoi::Print(vector<vector<Peg>> nodes) {
    for (int i = 0; i < nodes.size(); ++i) {
        Print("\n===========\nNode: " + to_string(i) + "\n");
        auto pegsToPrint = nodes[i];
        Print(pegsToPrint);
    }
}

void Hanoi::Print(vector<Peg> pegsToPrint) {
    string msg;
    for (int j = 0; j < pegsToPrint.size() ; ++j) {
        msg += "--------------\nPeg: " + to_string(j);
        msg += "\n" + pegsToPrint[j].ToString() + "\n";
    }
    Print(msg);
}




