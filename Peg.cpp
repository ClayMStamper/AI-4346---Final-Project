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

    if (Debug::Draw()) {
        for (int i = height - 1; i >= 0; --i) {
            string diskSpace = GetOffsetSpace(i);

            if (i > disks.size() - 1 || disks.size() == 0) { // draw pole
                frame += GetOffsetSpace(offset - 1) + pegChar;
            } else { //draw disk
                string pegSpace = GetOffsetSpace(offset);
                frame += diskSpace + disks[i].ToString();
            }

            if (i > 0)
                frame += "\n" + GetOffsetSpace(offset - 1) + pegChar + "\n"; //draw pole
        }
    } else {
        frame += "Disk count = " + to_string(disks.size());
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

bool Peg::HasDisk(int width) {
    for (int i = 0; i < disks.size(); ++i) {
        if (disks[i].width == width)
            return true;
    }
    return false;
}

bool Peg::operator==(Peg other) {

    if (disks.size() != other.disks.size())
        return false; //different amount of disks

    for (int i = 0; i < disks.size(); ++i) {
        if (disks[i].width != other.disks[i].width)
            return false; // disks not stacked the same way
    }

    return true;
}

