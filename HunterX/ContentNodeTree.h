//
// Created by Brandon on 10/26/2026.
//

#pragma once
#include "ContentNode.h"
#include "Controller.h"
#include <nlohmann/json_fwd.hpp>
#include <memory>
#include <queue>
#include <unordered_map>
#include "Player.h"


class ContentNodeTree {
private:
    contentNode root;
    contentNode* currentNode = &root;
    std::vector<std::unique_ptr<contentNode>> ownedNodes;
    std::queue<std::pair<contentNode*, std::string>> pendingReturns;
    std::unordered_map<std::string, contentNode*> nodesByID;

public:
    void toParent();
    void returnTo();
    void displayChildContent();
    void displayCurrentNode(Player& player);
    Input getAction();
    Controller input();
    void moveNodes(Player& player);
    void loadContent(std::string& filePath);
    void addContent(const nlohmann::json& data, contentNode* node);
};
