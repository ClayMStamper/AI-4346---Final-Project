//
// Created by clays on 11/23/2019.
//

#include "RBFS.h"

Node RBFS::ExpandNode(Node n) {

    if (openStack.Contains(n))
        openStack -= n;

    closedStack += n;

    GenerateNodes(n);
    auto minH = pair <Node, int>{Node(), 999999};

    for (auto & node : openStack.nodes) {
        int h = H(node); //distance to goal node if this node is expanded
        if (h < minH.second) {
            //  Debug::Log("Print H = " + to_string(h) + " for peg set: " + to_string(i));
            minH = {node, h};
        }
    }

    ++expanded;
    return minH.first;

}

RBFS::RBFS(int diskCount, Node startNode) {
    this->diskCount = diskCount;
    this->startNode = startNode;
}

