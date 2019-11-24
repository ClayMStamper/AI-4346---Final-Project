//
// Created by clays on 11/23/2019.
//

#include "Ai.h"

int Ai::G() {
    return 0;
}

int Ai::H(Node actual, Node goal) {
    int dist = 0;

    //if goal peg !has some disk
     // dist += disk.width squared

     Peg goalPeg = actual.pegs.back();
    for (int i = 0; i < actual.pegs.size(); ++i) {
        if (!goalPeg.HasDisk(i))
            dist += i * i;
    }

    return dist;
}

Node Ai::ExpandNode(NodeSet nodeSet, Node goal) {
    return Node(); //overridden by child classes
}

string Ai::ToString() {
    return "";
}


