//
// Created by clays on 11/23/2019.
//

#include "RBFS.h"

RBFS::RBFS(int diskCount, Node currentNode, Node goalNode)  {

    this->diskCount = diskCount;
    this->currentNode = currentNode;

    start = high_resolution_clock::now();

    int i = 0;
    for (; !(currentNode == goalNode); ++i) {
        print("Itr: " + to_string(i));
        currentNode.print();
        currentNode = ExpandNode(currentNode);
    }

    stop = high_resolution_clock::now();
    auto durationRaw = duration_cast<microseconds>(stop - start);
    timeDuration = durationRaw.count() / pow(10, 6);

    print("Itr: " + to_string(i));
    currentNode.print();

    PrintConclusion();

}


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

void RBFS::PrintConclusion() {
    string name = "RBFS";
    resultString = name + delim + to_string(diskCount) + delim + "h1" + delim + to_string(generated)
                   + delim + to_string(expanded) + delim + to_string(timeDuration);

    print("Nodes generated: " + to_string(generated) +
          "\nNodes expanded: " + to_string(expanded) + "\nTime duration: " + to_string(timeDuration));
}



