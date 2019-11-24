//
// Created by clays on 11/23/2019.
//

#include "Hanoi.h"

Hanoi::Hanoi(int pegCount, int diskCount) {
    startNode = Node();
    goalNode = Node();

    InitializeCurrent(pegCount, diskCount);
    InitializeTarget(pegCount, diskCount);
    brain = RBFS(diskCount);

    startNode = brain.ExpandNode(GenerateNodes(), goalNode);
    print(startNode.ToString());
    goalNode.print();

}

void Hanoi::InitializeCurrent(int pegCount, int diskCount) {
    startNode.pegs.emplace_back(diskCount, diskCount); //first peg with disks
    for (int i = 1; i < pegCount; ++i) {

        startNode.pegs.emplace_back(0, pegCount); // all other empty startNode->pegs
    }
}

void Hanoi::InitializeTarget(int pegCount, int diskCount) {
    for (int i = 0; i < pegCount - 1; ++i) {
        goalNode.pegs.emplace_back(0, pegCount); // all other empty startNode->pegs
    }
    goalNode.pegs.emplace_back(diskCount, diskCount); //first peg with disks
}

string Hanoi::ToString() {
    string msg;
    for (int i = 0; i < startNode.pegs.size() ; ++i) {
        msg += "\n--------------\nPeg: " + to_string(i) + "\n";
        msg += "\n" + startNode.pegs[i].ToString() + "\n";
    }
    return msg;
}

NodeSet Hanoi::GenerateNodes() {
    auto nodeSet = NodeSet({});//set of possible startNode->pegs
    for (int i = 0; i < startNode.pegs.size(); ++i) { //go through each actual peg

        auto openNodes = GenerateNodes(i); //get possible sets of startNode->pegs if this peg's disk is moved
        for (int j = 0; j < openNodes.Size(); ++j) { //loop through possible sets from this move
            nodeSet.nodes.push_back(openNodes.nodes[j]); //add possible sets to "nodeSet"
        }

    }
    return nodeSet;
}

NodeSet Hanoi::GenerateNodes(int thisPeg) {

    auto nodeSet = NodeSet({});

    for (int i = 0; i < startNode.pegs.size(); ++i) {
        if (thisPeg != i && CanMove(startNode.pegs[thisPeg], startNode.pegs[i])){
            //print("current: \n" + startNode.ToString());
            Node newNode = Node(startNode.pegs);
            //print("tmp copied pegs: \n" + newNode.ToString());
            Disk moveDisk = startNode.pegs[thisPeg].disks.back();
            newNode.pegs[thisPeg].disks.pop_back();
            newNode.pegs[i].disks.push_back(moveDisk);
            nodeSet.nodes.emplace_back(newNode);
        }
    }

    return nodeSet;
}

bool Hanoi::CanMove(Peg a, Peg b) {

    if (a.disks.empty())
        return false;
    if (b.disks.empty())
        return true;
    return (a.disks.back().width < b.disks.back().width);

}






