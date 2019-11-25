//
// Created by clays on 11/23/2019.
//

#ifndef AI_PROJ2_RBFS_H
#define AI_PROJ2_RBFS_H

#include "Ai.h"

class RBFS : public Ai {

private: // private fields

public: //public methods
    RBFS(int diskCount, Node currentNode, Node goalNode);
    RBFS () = default;
    ~RBFS() = default;
    Node ExpandNode(Node n) override;
    void PrintConclusion() override;

private: // private methods

};


#endif //AI_PROJ2_RBFS_H
