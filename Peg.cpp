//
// Created by clays on 11/22/2019.
//

#include "Peg.h"

Peg::Peg(int ringCount, int height) {
    disks = std::vector<Disk>();
    for (int i = ringCount; i > 0; --i) {
        Disk newDisk = Disk(i);
        disks.push_back(newDisk);
    }
    offset = disks.size();
    this->height = height;
}

string Peg::ToString() {

    string frame;

    for (int i = height - 1; i >= 0; --i) {
        string diskSpace = GetOffsetSpace(i);

        if (i > disks.size() - 1 || disks.size() == 0){ // draw pole
            frame +=  GetOffsetSpace(offset - 1) + pegChar ;
        } else { //draw disk
            string pegSpace = GetOffsetSpace(offset);
            frame += diskSpace + disks[i].ToString();
        }

        if (i > 0)
            frame +=  "\n" + GetOffsetSpace(offset - 1) + pegChar  + "\n"; //draw pole
    }

    return frame;

}

string Peg::GetOffsetSpace(int width) {
    string space;

    for (int i = 0; i < width; ++i) {
        space += " ";
    }

    return space;
}
