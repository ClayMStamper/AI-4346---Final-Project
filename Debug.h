//
// Created by clays on 11/22/2019.
//

#ifndef AI_PROJ2_DEBUG_H
#define AI_PROJ2_DEBUG_H


#include <string>
#include "iostream"
using namespace std;


class Debug {
public: static bool Draw() { return false;}
public: static void Log(string msg);
};

class IConvertToString {
public:
    virtual string ToString(){
        return "";
    }
    static void print(string msg) {Debug::Log(std::move(msg));} //print some message
    void print() {print(ToString());}; //print this object

};




#endif //AI_PROJ2_DEBUG_H
