//
// Created by clays on 11/22/2019.
//

#ifndef AI_PROJ2_DEBUG_H
#define AI_PROJ2_DEBUG_H


#include <string>
#include "iostream"
using namespace std;

class Serializeable {
public:
    virtual string ToString(){
        return "";
    }
};

class Debug {
public:
    static void Log(string msg);
};



#endif //AI_PROJ2_DEBUG_H
