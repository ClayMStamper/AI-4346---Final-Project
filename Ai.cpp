//
// Created by clays on 11/23/2019.
//

#include "Ai.h"

int Ai::G() {
    return 0;
}

int Ai::H(Node actual) {
    int dist = 0;

    //if goal peg !has some disk
     // dist += disk.width squared

     Peg goalPeg = actual.pegs.back();

    dist -= pow (goalPeg.disks.size(), 3);

    for (int i = 1; i <= diskCount; ++i) { // check disks on final peg
        if (!goalPeg.HasDisk(i))
            dist += pow(2, i) - 1;
    }

    int pegCount = actual.pegs.size();
    for (Peg peg : actual.pegs) { //sort through all except goal peg
        if (peg.disks.size() > 0)
            dist -= pow(peg.disks.back().width, 2);
    }

    return dist;
}

Node Ai::ExpandNode(NodeSet nodeSet, Node goal) {
    return Node(); //overridden by child classes
}

string Ai::ToString() {
    return "";
}


