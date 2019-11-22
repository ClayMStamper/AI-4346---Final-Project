//
// Created by clays on 11/22/2019.
//

#include "Peg.h"

Peg::Peg(int ringCount) {
    disks = std::stack<Disk>();
    for (int i = ringCount; i > 0; --i) {
        Disk newDisk = Disk(i);
        disks.push(newDisk);
    }
}
