//
// Created by Brandon on 10/26/2026.
//
#pragma once
#include <iostream>
#include <vector>


class contentNode {
private:
    struct DialogueContent {
        std::string speaker;
        std::string text;
    };
    std::string textContent;
    std::string labelContent;
    contentNode* parent = nullptr;
    contentNode* returnTo = nullptr;
    std::vector<contentNode*> children;
    std::vector<DialogueContent> dialogueContent;
    std::string nodeType;



public:

    void setTextContent(const std::string& newContent);
    void setLabelContent(const std::string& newContent);
    void setNodeType(const std::string& newNodeType);
    void setDialogueContent(const std::string speaker, std::string text);
    void setParent(contentNode* newParent);
    void setReturn(contentNode* newReturn);
    void addChild(contentNode* newChild);
    [[nodiscard]]std::string getTextContent();
    [[nodiscard]]std::string getLabelContent();
    [[nodiscard]]std::string getNodeType();
    [[nodiscard]] contentNode* getParent() const;
    [[nodiscard]] contentNode* getReturnTo() const;
    [[nodiscard]] const std::vector<DialogueContent>& getDialogueContent() const;
    [[nodiscard]] const std::vector<contentNode*>& getChildren() const;
    bool isLeaf();


};
