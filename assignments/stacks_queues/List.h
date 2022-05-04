#pragma once 

#include "Node.h"

class List { 
    private: 
        Node *head;

    public: 
        List();
        ~List(); 
        void insert(std::string data);
        void insert(int loc, std::string data); 
        std::string toString(); 
        int locate(std::string data); 
        void remove(int location);
        std::string get(); 
};