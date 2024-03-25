//
// Created by Jun-Sik Choi on 3/24/24.
//

#ifndef ADDRESSBOOK_NODE_H
#define ADDRESSBOOK_NODE_H


class Node {
public:
    Node();

    virtual ~Node();

    void setNext(Node *nextPtr);

    Node* getNext() const;

protected:
    Node *next = nullptr;
};


#endif //ADDRESSBOOK_NODE_H
