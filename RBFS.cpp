//
// Created by clays on 11/23/2019.
//

#include "RBFS.h"

Node RBFS::ExpandNode(NodeSet nodeSet, Node goal) {

    auto minH = pair <Node, int>{nodeSet.nodes[0], 999999};

    for (int i = 0; i < nodeSet.nodes.size(); ++i) {
        int h = H(nodeSet.nodes[i], goal); //distance to goal node if this node is expanded
        if (h < minH.second) {
            Debug::Log("Print H = " + to_string(h) + " for peg set: " + to_string(i));
            minH = {nodeSet.nodes[i], h};
        }
    }

    return minH.first;

}

RBFS::RBFS(int diskCount) {
    this->diskCount = diskCount;
}

