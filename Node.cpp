//
// Created by clays on 11/23/2019.
//

#include "Node.h"

string Node::ToString() {
    string msg;
    for (int j = 0; j < pegs.size() ; ++j) {
        msg += "--------------\nPeg: " + to_string(j);
        msg += "\n" + pegs[j].ToString() + "\n";
    }
    return msg;
}

bool Node::operator==(Node other) {
    for (int i = 0; i < pegs.size(); ++i) {
        if (!(pegs[i] == other.pegs[i]))
            return false; //not all pegs are the same
    }
    return true;
}

Node::Node() {

    for (int i = 1; i < pegs.size(); ++i) {
        pegs[i].height = pegs[0].height;
        pegs[i].offset = pegs[0].offset;
    }

}

Node::Node(vector<Peg> pegs) {
    this->pegs = move(pegs);
    for (int i = 1; i < pegs.size(); ++i) {
        pegs[i].height = pegs[0].height;
        pegs[i].offset = pegs[0].offset;
    }
}
