//
// Created by clays on 11/22/2019.
//

#include "Debug.h"


void Debug::Log(string msg) {
    cout << endl << msg << endl;
}

void Debug::Log(IConvertToString msg) {
    cout << endl << msg.ToString() << endl;
}
