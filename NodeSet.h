//
// Created by clays on 11/23/2019.
//

#ifndef AI_PROJ2_NODESET_H
#define AI_PROJ2_NODESET_H

#include <utility>

#include "Node.h"

class NodeSet : public IConvertToString {

public:
    vector<Node> nodes = vector<Node>();

public:
    explicit NodeSet(vector<Node> nodes) {this->nodes = std::move(nodes); }
    ~NodeSet() = default;
    string ToString() override ;
    int Size() { return nodes.size();}

private:

};


#endif //AI_PROJ2_NODESET_H
