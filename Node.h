//
// Created by clays on 11/23/2019.
//

#ifndef AI_PROJ2_NODE_H
#define AI_PROJ2_NODE_H


#include <vector>
#include "Debug.h"
#include "Peg.h"

class Node : public IConvertToString {

public:
    vector<Peg> pegs;

private:

public:
    Node() = default;
    explicit Node(const vector<Peg>&) {this->pegs = std::move(pegs);};
    ~Node() = default;
    string ToString() override;
    int Size() { return  pegs.size();} //should always be 3

private:

};


#endif //AI_PROJ2_NODE_H
