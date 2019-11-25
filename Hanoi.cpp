//
// Created by clays on 11/23/2019.
//

#include "Hanoi.h"
#include "AStar.h"

#include "fstream"

Hanoi::Hanoi(int pegCount, int diskCount) {

    currentNode = Node();
    goalNode = Node();

    InitializeStart(pegCount, diskCount);
    InitializeGoal(pegCount, diskCount);

    Ai brain = Ai(diskCount, currentNode, goalNode);

    ofstream file;
    file.open("Results.csv");

    file << "Algorithm,n,Heuristic,#Nodes Generated,#Nodes Expanded,Execution Time\n";
    file << brain.resultString;

    file.close();

   // RBFS brain1 = RBFS(diskCount, currentNode);
   // AStar brain2 = AStar(diskCount, currentNode);

}

void Hanoi::InitializeStart(int pegCount, int diskCount) {
    currentNode.pegs.emplace_back(diskCount, diskCount); //first peg with disks
    for (int i = 1; i < pegCount; ++i) {

        currentNode.pegs.emplace_back(0, pegCount); // all other empty startNode->pegs
    }
}

void Hanoi::InitializeGoal(int pegCount, int diskCount) {
    for (int i = 0; i < pegCount - 1; ++i) {
        goalNode.pegs.emplace_back(0, pegCount); // all other empty startNode->pegs
    }
    goalNode.pegs.emplace_back(diskCount, diskCount); //first peg with disks
}

string Hanoi::ToString() {
    string msg;
    for (int i = 0; i < currentNode.pegs.size() ; ++i) {
        msg += "\n--------------\nPeg: " + to_string(i) + "\n";
        msg += "\n" + currentNode.pegs[i].ToString() + "\n";
    }
    return msg;
}

bool Hanoi::CanMove(Peg a, Peg b) {

    if (a.disks.empty())
        return false;
    if (b.disks.empty())
        return true;
    return (a.disks.back().width < b.disks.back().width);

}






