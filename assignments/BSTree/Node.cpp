#include "Node.h"

Node::Node() { 
    this->left = nullptr;
    this->right = nullptr;
    this->data = 0; 
}

Node::Node(int data) { 
    this->data = data; 
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(int data, Node *l, Node *r) { 
    this->data = data;
    this->left = l;
    this->right = r;
}

int Node::getData() { 
    return this->data;
}

Node * Node::getLeft() { 
    return this->left;
}

Node * Node::getRight() { 
    return this->right;
}

void Node::setData(int d) { 
    this->data = d; 
}

void Node::setRight(Node *r) { 
    this->right = r; 
}

void Node::setLeft(Node *l) { 
    this->left = l;
}