//
// Created by clays on 11/22/2019.
//

#ifndef AI_PROJ2_PEG_H
#define AI_PROJ2_PEG_H

#include "stack"
#include "Disk.h"
#include "Debug.h"

class Peg : public Serializeable {

public:
    std::stack<Disk> disks;
    Peg (int ringCount);

};


#endif //AI_PROJ2_PEG_H
