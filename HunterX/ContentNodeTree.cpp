//
// Created by Brandon on 10/26/2026.
//
#include "ContentNodeTree.h"
#include "Controller.h"
#include "TypeWrite.h"
#include "Player.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <stdexcept>
#include <string>
#include <queue>
#include <utility>
#include <thread>
#include <chrono>

void ContentNodeTree::toParent() {
    if (currentNode->getParent()) {
        currentNode = currentNode->getParent();
    }
}

void ContentNodeTree::returnTo() {
    if (currentNode->getReturnTo()) {
        currentNode = currentNode->getReturnTo();
    }
}

void ContentNodeTree::displayChildContent() {
    for (int i = 0; i < currentNode->getChildren().size(); i++) {
        std::cout << i + 1 << " " << currentNode->getChildren()[i]->getLabelContent() << std::endl;
    }
}

void ContentNodeTree::displayCurrentNode(Player& player) {
    std::string location = player.getCurrentLocation()->getName();
    std::string areaName = player.getCurrentLocation()->getArea()->name;
    if (currentNode->getNodeType() == "action") {
        if (!currentNode->getTextContent().empty()) {
            clearContentArea();
            typeWrite(currentNode->getTextContent());
		    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
            displayChildContent();
        }
    }
    if (currentNode->getNodeType() == "dialogue") {
        clearContentArea();
        for (const auto& content : currentNode->getDialogueContent()) {
            typeWrite(content.speaker + ": " + content.text);
		    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
        }
    }
    if (currentNode->getNodeType() == "interaction") {
        clearContentArea();
        typeWrite(currentNode->getTextContent());
    }
}

Input ContentNodeTree::getAction() {
    Controller controller;
    return controller.readAction();
}



void ContentNodeTree::moveNodes(Player& player) {
    bool atLocation = true;
    while (atLocation) {
        bool hasParent = currentNode->getParent();
        displayCurrentNode(player);
        //Check if Leaf node
        if (currentNode->isLeaf()) {
            std::cout << "Press Enter to continue..." << std::endl;
            Input action = getAction();
            if (action.action == Action::Enter) {
                returnTo();
            }

        }
        else {
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
                if (hasParent) {
                    toParent();
                }
                else if (!hasParent) {
                    atLocation = false;
                }
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

    addContent(data, &root);
    while (!pendingReturns.empty()) {
        const auto& pending = pendingReturns.front();
        contentNode* node = pending.first;
        const std::string& returnID = pending.second;
        auto nodeToFind = nodesByID.find(returnID);
        if (nodeToFind == nodesByID.end()) {
            throw::std::runtime_error("Content node not found" + returnID);
        }
        node->setReturn(nodeToFind->second);
        pendingReturns.pop();
    }
}

void ContentNodeTree::addContent(const nlohmann::json& data, contentNode* node) {
    if (data.contains("type")) {
        std::string type = data.at("type").get<std::string>();
        node->setNodeType(type);
        if (node->getNodeType() == "dialogue") {
            std::vector<std::string> dialogue;
            if (data.contains("returnID")) {
                std::string returnID = data.at("returnID").get<std::string>();
                pendingReturns.emplace(node, returnID);
            }
            if (data.contains("label")) {
                std::string label = data.at("label").get<std::string>();
                node->setLabelContent(label);
            }

            for (const auto& sentence : data.at("content")) {
                node->setDialogueContent(
                    sentence.at("speaker").get<std::string>(),
                    sentence.at("text").get<std::string>()
                    );
            }
        }
        else if (node->getNodeType() == "action") {
            if (data.contains("returnID")) {
                std::string returnID = data.at("returnID").get<std::string>();
                pendingReturns.emplace(node, returnID);
            }
            if (data.contains("text")) {
                node->setTextContent(data.at("text").get<std::string>());
            }
            if (data.contains("label")) {
                std::string label = data.at("label").get<std::string>();
                node->setLabelContent(label);
            }
            if (data.contains("choices")) {
                for (const auto& choice : data.at("choices")) {
                    auto child = std::make_unique<contentNode>();
                    contentNode* newChild = child.get();


                    ownedNodes.push_back(std::move(child));
                    node->addChild(newChild);
                    addContent(choice, newChild);
                }
            }
        }
        else if (node->getNodeType() == "interaction") {
            if (data.contains("returnID")) {
                std::string returnID = data.at("returnID").get<std::string>();
                pendingReturns.emplace(node, returnID);
            }
            if (data.contains("text")) {
                node->setTextContent(data.at("text").get<std::string>());
            }
            if (data.contains("label")) {
                std::string label = data.at("label").get<std::string>();
                node->setLabelContent(label);
            }
        }
    }
    std::string id = data.at("id").get<std::string>();
    auto result = nodesByID.emplace(id, node);
    if (!result.second) {
        throw::std::runtime_error("Content node already exists" + id);
    }
}


