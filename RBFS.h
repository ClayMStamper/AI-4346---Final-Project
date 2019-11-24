//
// Created by clays on 11/23/2019.
//

#ifndef AI_PROJ2_RBFS_H
#define AI_PROJ2_RBFS_H

#include "Ai.h"

class RBFS : public Ai {

private: // private fields

public: //public methods
    explicit RBFS(int diskCount);
    RBFS () = default;
    ~RBFS() = default;
    Node ExpandNode (NodeSet nodeSet, Node goal) override;

private: // private methods

};


#endif //AI_PROJ2_RBFS_H
