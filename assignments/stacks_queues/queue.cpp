#include <string>
#include <iostream>
#include "queue.h"

Queue::Queue() { 
    this->arr = new int[SIZE];
    this->start = 0;
    this->end = SIZE;
}

std::string Queue::print_debug_str() { 
    std::string tmp = "";
    tmp += "Start # of arr: " + std::to_string(this->start) + " | End of arr: " + std::to_string(this->end);

    return tmp;
}