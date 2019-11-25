//
// Created by clays on 11/23/2019.
//

#include "Ai.h"

Ai::Ai(int diskCount, Node currentNode, Node goalNode) {

    this->diskCount = diskCount;
    this->startNode = currentNode;

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


Node Ai::ExpandNode(Node n) {

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

int Ai::H(Node actual) {
    int dist = 0;

    Peg goalPeg = actual.pegs.back();

    for (int i = 1; i <= diskCount; ++i) { // check disks on final peg
        if (!goalPeg.HasDisk(i))
            dist += pow(2, i) - 1;
    }
    return dist;
}

int Ai::G() {
    return 0;
}

//generate all new nodes from the current node
void Ai::GenerateNodes(Node n) {

    for (int from = 0; from < n.pegs.size(); ++from) { //go through each actual peg
        for (int to = 0; to < n.pegs.size(); ++to) {
            if (from != to && CanMove(n.pegs[from], n.pegs[to])){
                //print("current: \n" + startNode.ToString());
                Node newNode = Node(n.pegs);
                //print("tmp copied pegs: \n" + newNode.ToString());
                Disk moveDisk = n.pegs[from].disks.back();
                newNode.pegs[from].disks.pop_back();
                newNode.pegs[to].disks.push_back(moveDisk);
                if (!openStack.Contains(newNode) && !closedStack.Contains(newNode)) {
                    ++generated;
                    openStack += newNode;
                }
            }
        }
    }

}

bool Ai::CanMove(Peg a, Peg b) {
    if (a.disks.empty())
        return false;
    if (b.disks.empty())
        return true;
    return (a.disks.back().width < b.disks.back().width);
}

string Ai::ToString() {
    return "";
}

void Ai::PrintConclusion() {

    string name = "RBFS";
    resultString = name + delim + to_string(diskCount) + delim + "h1" + delim + to_string(generated)
            + delim + to_string(expanded) + delim + to_string(timeDuration);

   print("Nodes generated: " + to_string(generated) +
   "\nNodes expanded: " + to_string(expanded) + "\nTime duration: " + to_string(timeDuration));

}


