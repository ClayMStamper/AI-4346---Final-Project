//
// Created by clays on 11/22/2019.
//

#ifndef AI_PROJ2_PEG_H
#define AI_PROJ2_PEG_H

#include "vector"
#include "Disk.h"
#include "Debug.h"

class Peg : public IConvertToString {

public:
    std::vector<Disk> disks;

public:
    Peg(int ringCount, int height);
    ~Peg() = default;
    string ToString() override;
    string GetOffsetSpace(int width);
    bool HasDisk(int width); // used to check goal peg for Heuristic
    bool operator == (Peg other);

private:
    string pegChar = "||";
    int offset, height;

};


#endif //AI_PROJ2_PEG_H
