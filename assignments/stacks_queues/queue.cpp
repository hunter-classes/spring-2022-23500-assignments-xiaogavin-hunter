#include <string>
#include <iostream>
#include "queue.h"

#define ERR_QUEUE_EMPTY 1
#define ERR_QUEUE_FULL 2
#define ERR_QUEUE_OTHER 4 

Queue::Queue() { 
    this->arr = new int[SIZE];
    this->start = 0;
    this->end = 0;
}

std::string Queue::print_debug_str() { 
    std::string tmp = "";
    tmp += "Start of arr: " + std::to_string(this->start) + " | End of arr: " + std::to_string(this->end) + "\n";

    for(int i = start; i < end; i++) { 
        tmp += std::to_string(arr[i]) + " ";
    }

    return tmp;
}

void Queue::enqueue(int a) { 
    if(end - start + 1 > SIZE) { 
        throw ERR_QUEUE_FULL;
    }

    arr[end] = a;
    end++;
}

int Queue::dequeue() {
    start++;
    return arr[start - 1];
}