//
// Created by clays on 11/23/2019.
//

#include "Hanoi.h"

Hanoi::Hanoi(int pegCount, int diskCount) {

    InitializePegs(pegCount, diskCount);
    brain = RBFS(diskCount);
    Print();

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

vector<Peg> *Hanoi::GenerateNodes() {
    return nullptr;
}

void Hanoi::Print(string msg) {
    Debug::Log(msg);
}


