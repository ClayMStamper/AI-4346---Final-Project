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

bool NodeSet::Contains(Node node) {
    for (auto & i : nodes) {
        if (i == node)
            return true;
    }
    return false;
}

void NodeSet::operator+=(Node other) {
    nodes.push_back(other);
}

void NodeSet::operator-=(Node other) {
    if (!Contains(other)){
        print("======\nERROR: removing node from NodeSet that doesnt contain it\n=======");
        return;
    }
    for (int i = 0; i < nodes.size(); ++i) {
        if (nodes[i] == other)
            nodes.erase(nodes.begin() + i);
    }
}

