//
// Created by clays on 11/23/2019.
//

#include "NodeSet.h"

string NodeSet::ToString() {
    string msg;
    for (int i = 0; i < nodes.size(); ++i) {
        msg += "\n===========\nNode: " + to_string(i) + "\n";
        msg += nodes[i].ToString();
    }
    return msg;
}
