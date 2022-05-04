#include "BSTree.h"
#include <iostream>

#define ERR_VAL_NOT_FOUND 1
#define ERR_VAL_EXISTS 2

BSTree::BSTree() { this->root = nullptr; }

void BSTree::insert(int d) {
    Node *t = root;
    Node *walker;

    Node *insrt = new Node(d);

    while (t) {
        walker = t;

        if (t->getData() == d) {
            throw ERR_VAL_EXISTS;
        }

        if (t->getData() > d) {
            t = t->getLeft();
        } else {
            t = t->getRight();
        }
    }

    if (!root) {
        root = insrt;
    } else if (walker->getData() > d) {
        walker->setLeft(insrt);
    } else {
        walker->setRight(insrt);
    }
}

void BSTree::rinsert(int d) {
    Node *head = root;
    Node *trailer;

    /* base case */
    if (!root) {
        root = new Node(d);
        return;
    }

    if (root->getData() == d) {
        throw ERR_VAL_EXISTS;
    }

    if (head->getData() > d) {
        trailer = head;
        head = head->getLeft();
        rinsert(d, head, trailer);
    } else {
        trailer = head;
        head = head->getRight();
        rinsert(d, head, trailer);
    }
}

void BSTree::rinsert(int d, Node *head, Node *trailer) {
    if (!head) {
        if (trailer->getData() > d) {
        trailer->setLeft(new Node(d));
        return;
    } else {
        trailer->setRight(new Node(d));
        return;
    }

    throw ERR_VAL_EXISTS;
}

    Node *next = head;
    Node *previous = trailer;

    if (next->getData() > d) {
        previous = next;
        next = head->getLeft();
        rinsert(d, next, previous);
    } else if (next->getData() < d) {
        previous = next;
        next = head->getRight();
        rinsert(d, next, previous);
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
    if (n) {
        return transverse(n->getLeft()) + std::to_string(n->getData()) + "-->" + transverse(n->getRight());
    }

    return "";
}

std::string BSTree::get_debug_string() {
    std::string tmp = "";

    if (!root) {
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

    if (!t) {
        throw ERR_VAL_NOT_FOUND;
    }

    int tval = t->getData();

    if (val == tval) {
        return val;
    }

    if (val > tval) {
        return rsearch(val, t->getRight());
    } else {
        return rsearch(val, t->getLeft());
    }

    throw ERR_VAL_NOT_FOUND;
}

int BSTree::rsearch(int val, Node *next) {
    Node *t = next;

    if (!t) {
        throw ERR_VAL_NOT_FOUND;
    }

    int tval = t->getData();

    if (val == tval) {
        return val;
    }

    if (val > tval) {
        return rsearch(val, t->getRight());
    } else {
        return rsearch(val, t->getLeft());
    }

    throw ERR_VAL_NOT_FOUND;
}

int BSTree::search(int value) {
    Node *t = root;

    while (t != nullptr) {
        int tval = t->getData();
        if (tval == value) {
            // here we'd really return a full object
            // with all the stuff associated with value
            // not just an int
            return value;
        }

        if (tval < value) {
            t = t->getRight();
        } else {
            t = t->getLeft();
        }
    }

    throw ERR_VAL_NOT_FOUND;
}

int BSTree::treesum() { 
    return treesum(root);
}

int BSTree::treesum(Node *next) { 
    if(!next) {
        return 0;
    }

    return treesum(next->getLeft()) + next->getData() + treesum(next->getRight());
}

void BSTree::remove(int i) { 
    /* 
     * base case
     * return when it doesn't exist within tree      
    */

    try { 
        rsearch(i);
    } catch(int e) { 
        return; 
    }

    Node *walker = root; 
    Node *trailer; 

    while(walker) { 
        if(walker->getData() == i) { 
            break;
        }

        trailer = walker; 

        if (walker->getData() < i) {
            walker = walker->getRight();
        } else {
            walker = walker->getLeft();
        }
    }

    // Check if its a leaf 
    if(!walker->getLeft() && !walker->getRight()) {
        if(trailer->getLeft()) { 
            trailer->setLeft(nullptr);
        } else {
            trailer->setRight(nullptr);
        }

        walker = nullptr;
        delete walker;
        return;
    }

    // One child 

    if(walker->getLeft() && !walker->getRight()) {
        trailer->setLeft(walker->getLeft());
        walker = nullptr;
        delete walker;
        return;
    }

    if(!walker->getLeft() && walker->getRight()) {
        trailer->setRight(walker->getRight());
        walker = nullptr;
        delete walker;
        return;
    }

    // has two childs 


}