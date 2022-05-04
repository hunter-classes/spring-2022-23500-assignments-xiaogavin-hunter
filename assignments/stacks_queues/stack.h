#pragma once 

#include "List.h"

class Stack { 

    /* Stack is LAST IN FIRST OUT 
     * // Constructor/destructors
     * push(int) // (you can change the type to std::string if you'd like)
     * int pop() // remove and return the top item
     * int top() // return but do not remove the top item
     * bool is_empty() // return true if empty, false otherwise
     */

    private: 
        int items; 
        List *head; 

    public:
        Stack();
        Stack(std::string item);
        ~Stack(); 

        // pushes item onto Stack
        void push(std::string item);

        // removes and returns top item 
        std::string pop();

        // returns top item 
        std::string top();

        // check to see if the list is empty 
        bool is_empty();

        std::string print();


};