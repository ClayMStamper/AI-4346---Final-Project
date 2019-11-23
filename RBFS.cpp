//
// Created by clays on 11/23/2019.
//

#include "RBFS.h"

vector<Peg> RBFS::ExpandNode(vector<vector<Peg>> pegSets) {

    auto minH = pair <vector<Peg>, int>{pegSets[0], 999999};

    for (int i = 0; i < pegSets.size(); ++i) {
        int h = H(pegSets[i]); //distance to goal node if this node is expanded
        if (h < minH.second)
            minH = {pegSets[i], h};
    }

    return minH.first;

}

RBFS::RBFS(int diskCount) {
    this->diskCount = diskCount;
}

