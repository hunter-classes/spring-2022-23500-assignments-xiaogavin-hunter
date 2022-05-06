#pragma once 
#include "Node.h"
#include <string>

class BSTree { 
    private: 
        Node *root; 
        int rsearch(int val, Node *next);
        void rinsert(int d, Node *head, Node *trailer);
        int treesum(Node *next);
        Node* get_leaf(Node* n);

    public:
        BSTree();
        void insert(int d);
        std::string get_debug_string();
        void setup(); 
        int rsearch(int val);
        void rinsert(int d);
        int search(int value);
        int treesum();
        void remove(int i); 
};
