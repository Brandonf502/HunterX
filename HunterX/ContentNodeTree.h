//
// Created by Brandon on 10/26/2026.
//

#pragma once
#include "ContentNode.h"
#include "Controller.h"

class ContentNodeTree {
private:
    contentNode root;
    contentNode* currentNode = &root;
public:
    void toParent();
    void displayChildContent();
    void displayCurrentNode();
    Input getAction();
    Controller input();
    void moveNodes();
};
