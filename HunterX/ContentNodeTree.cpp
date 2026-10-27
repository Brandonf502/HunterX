//
// Created by Brandon on 10/26/2026.
//
#include "ContentNodeTree.h"
#include "Controller.h"

void ContentNodeTree::toParent() {
    if (currentNode->getParent()) {
        currentNode = currentNode->getParent();
    }
}

void ContentNodeTree::displayChildContent() {
    for (int i = 0; i < currentNode->getChildren().size(); i++) {
        std::cout << i + 1 << " " << currentNode->getChildren()[i]->getTextContent() << std::endl;
    }
}

void ContentNodeTree::displayCurrentNode() {
    std::string text = currentNode->getTextContent();
    std::cout << text << std::endl;
}

Input ContentNodeTree::getAction() {
    return controller.readAction();
}

void ContentNodeTree::moveNodes() {
    bool atLocation = true;
    while (atLocation) {
        bool hasParent = currentNode->getParent();
        displayCurrentNode();
        //Check if Leaf node
        if (currentNode->getChildren().empty()) {
            std::cout << "Press Enter to continue..." << std::endl;
            Input action = getAction();
            if (action.action == Action::Enter) {
                toParent();
            }
        }
        else {
            displayChildContent();
            if (hasParent) {
                std::cout << "Press BackSpace to go back" << std::endl;
            }
            Input action = getAction();
            int choices = static_cast<int>(currentNode->getChildren().size());
            if (action.action == Action::Number &&
                action.number >= 1 &&
                action.number <= choices) {
                currentNode = currentNode->getChildren()[action.number - 1];
                }
            else if (action.action == Action::Back) {
                toParent();
            }

        }

    }
}


