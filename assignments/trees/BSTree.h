#pragma once 
#include "Node.h"
#include <string>

class BSTree { 
    private: 
        Node *root; 
        int rsearch(int val, Node *next);

    public:
        BSTree();
        void insert(int d);
        std::string get_debug_string();
        void setup(); 
        int rsearch(int val);
        

};
