//
// Created by clays on 11/23/2019.
//

#include "RBFS.h"
#include "map"

vector<Peg> RBFS::ExpandNode(vector<vector<Peg>> pegsSets) {

    Disk disk = pegsSets[0][0].disks.back();
    pegsSets[0][0].disks.pop_back();
    pegsSets[0][1].disks.push_back(disk);

    return pegsSets[0];

}

RBFS::RBFS(int diskCount) {
    this->diskCount = diskCount;
}

