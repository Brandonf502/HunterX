//
// Created by Brandon on 10/26/2026.
//

#include "ContentNode.h"

void contentNode::setTextContent(const std::string& newContent) {
    this->textContent = newContent;
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

contentNode* contentNode::getParent() const{
    return this->parent;
}

contentNode* contentNode::getReturnTo() const {
    return this->returnTo;
}

const std::vector<contentNode*>& contentNode::getChildren() const {
    return this->children;
}
