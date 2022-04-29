#include "BSTree.h"

BSTree::BSTree() { 
    this->root = nullptr; 
}

void BSTree::insert(int d) { 

}

void BSTree::setup() {
    Node *n = new Node(10);
    root = n;
    n = new Node(20);
    root->setRight(n);
    Node *n2 = new Node(30);
    n->setRight(n2);
    n2 = new Node(15);
    n->setLeft(n2);
    n2 = new Node(5);
    root->setLeft(n2);
    n = new Node(3);
    n2->setLeft(n);
    n = new Node(7);
    n2->setRight(n);
 
}

std::string transverse(Node *n) { 
    if(n) { 
        return transverse(n->getLeft()) + std::to_string(n->getData()) + "-->" + transverse(n->getRight()); 
    }

    return "";
}

std::string BSTree::get_debug_string() { 
    std::string tmp = "";

    if(!root) { 
        return "";  
    } else { 
        tmp = transverse(root);
    }

    return tmp + "nullptr"; 
}

