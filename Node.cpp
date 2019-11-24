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
