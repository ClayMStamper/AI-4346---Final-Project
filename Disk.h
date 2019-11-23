//
// Created by clays on 11/22/2019.
//


#ifndef AI_PROG2_DISK_H
#define AI_PROG2_DISK_H


#include <string>
#include "Debug.h"

class Disk : public IConvertToString {

public: // public fields
    int width;

public: //public methods
    Disk(int);
    ~Disk() = default;
    bool CanStackOn(Disk);
    string ToString() override;

private:
    string diskChar = "==";

};


#endif //AI_PROG2_DISK_H
