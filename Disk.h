//
// Created by clays on 11/22/2019.
//


#ifndef AI_PROG2_DISK_H
#define AI_PROG2_DISK_H


#include <string>
#include "Debug.h"

class Disk : public Serializeable {

public:
    int width;
    Disk(int);
    bool CanStackOn(Disk);
    string ToString() override;
};


#endif //AI_PROG2_DISK_H
