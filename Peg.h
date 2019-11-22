//
// Created by clays on 11/22/2019.
//

#ifndef AI_PROJ2_PEG_H
#define AI_PROJ2_PEG_H

#include "vector"
#include "Disk.h"
#include "Debug.h"

class Peg : public Serializeable {

public:
    std::vector<Disk> disks;
    Peg (int ringCount);
    string ToString();

private:
    string pegChar = "|";

};


#endif //AI_PROJ2_PEG_H
