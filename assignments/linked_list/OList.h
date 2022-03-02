#pragma once 

#include "ONode.h"
#include <string>


class OList { 
    private: 
        ONode *head; 

    public: 
        // Constructor 
        OList(); 
        // Destructor 
        ~OList(); 
        // @param value, inserts value at proper location 
        void insert(int value); 

        // @return string, toString of the list
        std::string toString();

        // @return bool, check if list contains value in the list 
        bool contains(int value);

        // @return int @param location, returns value at location
        int get(int location); 

        // @param location, remove value at location 
        void remove(int location); 

        // reverse list into reversed order 
        void reverse(); 

};