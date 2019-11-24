//
// Created by clays on 11/23/2019.
//

#include "RBFS.h"

Node RBFS::ExpandNode(Node n) {

    auto minH = pair <Node, int>{openStack.nodes[0], 999999};

    for (int i = 0; i < openStack.nodes.size(); ++i) {
        int h = H(openStack.nodes[i]); //distance to goal node if this node is expanded
        if (h < minH.second) {
          //  Debug::Log("Print H = " + to_string(h) + " for peg set: " + to_string(i));
            minH = {openStack.nodes[i], h};
        }
    }

    return minH.first;

}

RBFS::RBFS(int diskCount) {
    this->diskCount = diskCount;
}

