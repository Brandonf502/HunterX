//
// Created by Brandon on 10/26/2026.
//

#include "ContentNode.h"

void contentNode::setTextContent(const std::string& newContent) {
    this->textContent = newContent;
}

void contentNode::setLabelContent(const std::string& newContent) {
    this->labelContent = newContent;
}

void contentNode::setNodeType(const std::string& newNodeType) {
    this->nodeType = newNodeType;
}

void contentNode::setDialogueContent(const std::string speaker, std::string text) {
    dialogueContent.push_back(DialogueContent{speaker, text});
}

void contentNode::setParent(contentNode* newParent) {
    this->parent = newParent;
}

void contentNode::setReturn(contentNode* newReturn) {
    this->returnTo = newReturn;
}

void contentNode::addChild(contentNode* newChild) {
    newChild->parent = this;
    this->children.push_back(newChild);

}

std::string contentNode::getTextContent() {
    return this->textContent;
}

std::string contentNode::getLabelContent() {
    return this->labelContent;
}

std::string contentNode::getNodeType() {
    return this->nodeType;
}
const std::vector<contentNode::DialogueContent>& contentNode::getDialogueContent() const {
    return this->dialogueContent;
}

contentNode* contentNode::getParent() const{
    return this->parent;
}

contentNode* contentNode::getReturnTo() const {
    return this->returnTo;
}

const std::vector<contentNode*>& contentNode::getChildren() const {
    return this->children;
}
bool contentNode::isLeaf() {
    if (this->children.empty()) {
        return true;
    }
    return false;
}
