//
// Created by Brandon on 10/26/2026.
//
#pragma once
#include <iostream>
#include <vector>

class contentNode {
private:
    std::string textContent;
    contentNode* parent = nullptr;
    contentNode* returnTo = nullptr;
    std::vector<contentNode*> children;

public:
    void setTextContent(const std::string& newContent);
    void setParent(contentNode* newParent);
    void setReturn(contentNode* newReturn);
    void addChild(contentNode* newChild);
    std::string getTextContent();
    [[nodiscard]] contentNode* getParent() const;
    [[nodiscard]] contentNode* getReturnTo() const;
    [[nodiscard]] const std::vector<contentNode*>& getChildren() const;
};
