//
// Created by clays on 11/22/2019.
//

#include "Disk.h"

Disk::Disk(int width) {
    this->width = width;
}

bool Disk::CanStackOn(Disk disk){

    return this->width < disk.width;

}

string Disk::ToString() {

    string line;



    return line;
}