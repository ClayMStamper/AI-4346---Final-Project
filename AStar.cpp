//
// Created by clays on 11/23/2019.
//

#include "AStar.h"
#include "NodeSet.h"

AStar::AStar(int diskCount, Node startNode, Node goalNode) {

    this->diskCount = diskCount;
    this->currentNode = startNode;

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

Node AStar::ExpandNode(Node n) {
    if (openStack.Contains(n))
        openStack -= n;

    closedStack += n;

    GenerateNodes(n);
    auto minF = pair <Node, int>{Node(), 999999};

    for (auto & node : openStack.nodes) {
        int h = H(node); //distance to goal node if this node is expanded
        int g = G(node);
        int f = g+h;
        if (f < minF.second) {
            //  Debug::Log("Print H = " + to_string(h) + " for peg set: " + to_string(i));
            minF = {node, h};
        }
    }

    ++expanded;
    return minF.first;
}

int AStar::G(Node actual) {
    int dist = 0;

    Peg startPeg = actual.pegs.front();

    for (int i = 1; i <= diskCount; ++i) { // check disks on final peg
        if (!startPeg.HasDisk(i))
            dist -= pow(2, i) - 1;
    }
    return dist;
}

void AStar::PrintConclusion() {

    resultString = name + delim + to_string(diskCount) + delim + "h1" + delim + to_string(generated)
                   + delim + to_string(expanded) + delim + to_string(timeDuration);

    print("Nodes generated: " + to_string(generated) +
          "\nNodes expanded: " + to_string(expanded) + "\nTime duration: " + to_string(timeDuration));
}



