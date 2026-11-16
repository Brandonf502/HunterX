//
// Created by Brandon on 10/26/2026.
//
#include "ContentNodeTree.h"
#include "Controller.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <stdexcept>
#include <string>

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
    Controller controller;
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

void ContentNodeTree::loadContent(std::string& filePath) {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        throw::std::runtime_error("Unable to open file" + filePath);
    }

    nlohmann::json data;
    file >> data;

    std::string id = data.at("id").get<std::string>();
    std::cout << "Loaded Node: " << id << std::endl;
    addContent(data, &root);
    displayCurrentNode();
}

void ContentNodeTree::addContent(const nlohmann::json& data, contentNode* node) {
    node->setTextContent(data.at("text").get<std::string>());
}


