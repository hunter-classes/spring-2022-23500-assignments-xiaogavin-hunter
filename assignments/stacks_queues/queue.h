#pragma once

const int SIZE = 8;

class Queue { 
    public:
        Queue();

        // Adds item to back of queue
        void enqueue(int a);

        // removes item from the start of queue & returns item 
        int dequeue();

        // returns items from start of queue
        int front();

        // check to see if arr is empty 
        bool is_empty();

        // check to see if arr is full
        bool is_full();

        std::string print_debug_str();

    private:
        int *arr;
        int start, end;
};