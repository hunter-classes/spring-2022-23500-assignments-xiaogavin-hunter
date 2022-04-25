#include "BSTree.h"

BSTree::BSTree() { 
    this->root = nullptr; 
}

void BSTree::insert(int d) { 

}

void BSTree::setup() { 
    Node *n = new Node(10); 
    this->root = n;
    n = new Node(20);
    this->root->setLeft(n);
    n = new Node(30);
    this->root->setRight(n);
    n = new Node(40);
    this->root->getLeft()->setLeft(n);

}

std::string transverse(Node *n) { 
    if(!n) { 
        return std::to_string(n->getData()) + "-->" + transverse(n->getLeft()) + transverse(n->getRight()); 
    } else {
        return "";
    }

    return "";
}

std::string BSTree::get_debug_string() { 
    std::string tmp = "";

    if(!root) { 
        return transverse(root);  
    } else { 
        tmp = std::to_string(root->getData());
    }

    return tmp; 
}