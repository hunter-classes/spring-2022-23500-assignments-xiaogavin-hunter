#include "BSTree.h"

#define ERR_VAL_NOT_FOUND 1

BSTree::BSTree() { 
    this->root = nullptr; 
}

void BSTree::insert(int d) { 
    Node *t = root;
    Node *walker;

    Node *insrt = new Node(d);

    while(t) {
        walker = t; 

        if(t->getData() == d) {
            return;
        }

        if(t->getData() > d) {
            t = t->getLeft();
        } else {
            t = t->getRight();
        }
    }

    if(!root) {
        root = insrt;
    } else if(walker->getData() > d) { 
        walker->setLeft(insrt);
    } else {
        walker->setRight(insrt);
    }
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

/* 

*             20
*          15    21
*
*
*/

int BSTree::rsearch(int val) {
    Node *t = root; 

    if(!t) {
        throw ERR_VAL_NOT_FOUND;
    }

    int tval = t->getData();
    
    if(val == tval) { 
        return val; 
    }

    if(val > tval) {
        return rsearch(val, t->getRight());
    } else {
        return rsearch(val, t->getLeft());
    }

    throw ERR_VAL_NOT_FOUND;
} 


int BSTree::rsearch(int val, Node *next) {
    Node *t = next; 

    if(!t) {
        throw ERR_VAL_NOT_FOUND;
    }

    int tval = t->getData();
    
    if(val == tval) { 
        return val; 
    }

    if(val > tval) {
        return rsearch(val, t->getRight());
    } else {
        return rsearch(val, t->getLeft());
    }

    throw ERR_VAL_NOT_FOUND;
} 