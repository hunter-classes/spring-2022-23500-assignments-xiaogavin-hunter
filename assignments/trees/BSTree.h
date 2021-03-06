#pragma once 
#include "Node.h"
#include <string>
#include <vector>

#define ERR_OTHER               1
#define ERR_VAL_NOT_FOUND       2
#define ERR_VAL_EXISTS          4
#define ERR_OUT_OF_BOUNDS       8

class BSTree { 
    private: 
        Node *root; 
        int rsearch(int val, Node *next);
        void rinsert(int d, Node *head, Node *trailer);
        int treesum(Node *next);
        Node* get_leaf(Node *n);
        int count_leaves(Node *n);
        int get_height(Node *n, int height);

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
        int count_leaves();

        // One based counting, starts from 1
        int get_height();

        int sum_of_given_level(int level);
};
