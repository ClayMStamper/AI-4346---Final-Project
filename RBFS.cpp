//
// Created by clays on 11/23/2019.
//

#include "RBFS.h"

vector<Peg> *RBFS::ExpandNode(vector<Peg> *pegs) {
    return Ai::ExpandNode(pegs);
}

RBFS::RBFS(int diskCount) {
    this->diskCount = diskCount;
}

