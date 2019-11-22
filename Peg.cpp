//
// Created by clays on 11/22/2019.
//

#include "Peg.h"

Peg::Peg(int ringCount) {
    disks = std::vector<Disk>();
    for (int i = ringCount; i > 0; --i) {
        Disk newDisk = Disk(i);
        disks.push_back(newDisk);
    }
}

string Peg::ToString() {

    string frame;

    for (int i = 0; i < disks.size(); ++i) {
        frame += pegChar + "\n"; //draw pole
        frame += disks[i].ToString();
    }

    return frame;

}
