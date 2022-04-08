#include "stack.h"
// #include <exception>

Stack::Stack() {
    items = 0; 
    // head = new List();
}

Stack::Stack(std::string item) { 
    items = 1; 
    head = new List();
    head->insert(item);
}

void Stack::push(std::string item) {
    head->insert(item); 
    items++; 
}

std::string Stack::pop() { 
    if(items <= 0) { 
        throw std::__throw_out_of_range;
    }
    
    std::string tmp = head->get();
    head->remove(0);
    items--;

    return tmp;
}