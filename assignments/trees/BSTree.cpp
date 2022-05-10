#include "BSTree.h"
#include <iostream>

#define ERR_OTHER               1
#define ERR_VAL_NOT_FOUND       2
#define ERR_VAL_EXISTS          4
#define ERR_OUT_OF_BOUNDS       8

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
        throw e; 
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
    Node *left = get_leaf(walker); // Node previous of left value that should be replaced 
    walker->setData(left->getLeft()->getData());
    left->setLeft(nullptr);
}

Node* BSTree::get_leaf(Node *n) { 
    Node *left; 

    while(n) { 
        if(n->getLeft()) {
            left = n;
        }

        n = n->getRight(); 
    } 

    return left; 

}

int BSTree::count_leaves() {
    if(!root) { 
        return 0;
    } 

    if(!root->getLeft() && !root->getRight()) {
        return 1; 
    }

    return count_leaves(root->getLeft()) + count_leaves(root->getRight()); 
}

int BSTree::count_leaves(Node *n) { 
    if(!n) {
        return 0;
    }

    if(!n->getLeft() && !n->getRight()) { 
        return 1;
    }

    return count_leaves(n->getLeft()) + count_leaves(n->getRight());
}


// height of tree: 3
int BSTree::get_height() { 
    if(!root) { 
        return 0; 
    }

    int left = 1, right = 1; 

    if(root->getLeft()) {
        left = get_height(root->getLeft(), left + 1);
    }

    if(root->getRight()) {
        right = get_height(root->getRight(), right + 1);
    }

    return left <= right ? right : left;  
}

int BSTree::get_height(Node *n, int height) { 
    if(!n->getLeft() && !n->getRight()) { 
        return height; 
    }

    int left = 0, right = 0;

    if(n->getLeft()) {
        left = get_height(n->getLeft(), height + 1);
    }

    if(n->getRight()) {
        right = get_height(n->getRight(), height + 1);
    }

    return left <= right ? right : left;
}

int BSTree::sum_of_given_level(int l) {
    if(l > this->get_height() || l <= 0) {
        throw ERR_OUT_OF_BOUNDS;
    } 

    if(l == 1) {
        return root->getData();
    }

    Node *left = root;
    Node *right = root;

    std::vector<Node*> current_nodes;
    current_nodes.push_back(root);

    while(l-- != 1) {
        std::vector<Node*> tmp; 
        for(auto node : current_nodes) {
            if(node->getLeft()) {
                tmp.push_back(node->getLeft());
            }

            if(node->getRight()) {
                tmp.push_back(node->getRight());
            }
        }

        current_nodes = tmp; 
    }

    int sum = 0;
    for(auto node : current_nodes) {
        sum += node->getData();
    }


    return sum;
}
