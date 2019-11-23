//
// Created by clays on 11/22/2019.
//

#include "iostream"

#include "Disk.h"
#include "Peg.h"
#include "Debug.h"

using namespace std;

int main (){

    int pegCount  = 3;
    Peg peg1 = Peg(pegCount, pegCount);
    Peg peg2 = Peg(0, pegCount);
    Peg peg3 = Peg(0, pegCount);
    vector<Peg> pegs = {peg1, peg2, peg3};


    Debug::Log(pegs.back().ToString());

    for (int i = 0; i < pegs.size() ; ++i) {
        cout << "--------------\nPeg: " << i << endl;
        Debug::Log(pegs[i].ToString());
    }


    return 0;
}