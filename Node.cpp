//
// Created by Jun-Sik Choi on 3/24/24.
//

#include "Node.h"

Node::Node() = default;

Node::~Node() = default;

void Node::setNext(Node *nextPtr) {
    this->next = nextPtr;
}

Node* Node::getNext() const {
    return this->next;
}