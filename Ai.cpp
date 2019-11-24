//
// Created by clays on 11/23/2019.
//

#include "Ai.h"

int Ai::G() {
    return 0;
}

int Ai::H(Node actual, Node goal) {
    int dist = 0;

    print ("Goal pegs" + to_string(goal.pegs.size()));
    print ("Actual pegs" + to_string(actual.pegs.size()));

    for (int i = 0; i < actual.pegs.size(); ++i) {
      //  int goalPeg = goal.pegs[i].disks.size();
        //int actualPeg = current.pegs[i].disks.size();
      //  dist += abs(goalPeg - actualPeg); //difference in disk count on each peg
    }
    return dist;
}

Node Ai::ExpandNode(NodeSet nodeSet, Node goal) {
    return Node(); //overridden by child classes
}

string Ai::ToString() {
    return "";
}


