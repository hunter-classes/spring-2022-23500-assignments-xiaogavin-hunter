#include "stack.h"

#define ERR_STACK_EMPTY 1
#define ERR_STACK_FULL 2

Stack::Stack() {
    items = 0; 
    head = new List();
}

Stack::Stack(std::string item) { 
    items = 1; 
    head = new List();
    head->insert(item);
}

Stack::~Stack() { 
    delete head;
    items = 0;
}

std::string Stack::print() { 
    return head->toString();
}

void Stack::push(std::string item) {
    head->insert(item); 
    items++; 
}

std::string Stack::pop() { 
    if(items <= 0) { 
        throw ERR_STACK_EMPTY;
    }
    
    std::string tmp = head->get();
    head->remove(0);
    items--;

    return tmp;
}

std::string Stack::top() { 
    if(items <= 0) { 
        throw ERR_STACK_EMPTY;
    }

    return head->get(); 
}

bool Stack::is_empty() { 
    return items == 0;
}