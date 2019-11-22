//
// Created by clays on 11/22/2019.
//

#include "iostream"

#include "Disk.h"
#include "Peg.h"
#include "Debug.h"

using namespace std;

int main (){

    Peg peg1 = Peg(3);
    Debug::Log(peg1.ToString());

    return 0;
}