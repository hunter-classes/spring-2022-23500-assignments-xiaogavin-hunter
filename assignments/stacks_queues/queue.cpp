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
    this->total_items = 0;  
}

Queue::~Queue() { 
    delete[] this->arr;
    this->start = 0;
    this->end = 0;
    this->total_items = 0;
}

bool Queue::is_empty() {
    return start == end && total_items < 1;  
}

bool Queue::is_full() {
    return start == end && total_items > 0 ; 
}

void Queue::enqueue(int i) { 
    if(is_full()) { 
        throw ERR_QUEUE_FULL;
    }

    arr[end] = i; 
    end++; 
    total_items++; 

    if(end >= SIZE) { 
        end %= SIZE; 
    }

}

int Queue::dequeue() { 
    if(is_empty()) { 
        throw ERR_QUEUE_EMPTY; 
    }

    int tmp = arr[start];
    start++;
    total_items--;

    if(start >= SIZE) { 
        start %= SIZE;
    }

    return tmp; 
}

int Queue::front() { 
    if(is_empty()) { 
        throw ERR_QUEUE_EMPTY;
    }

    return arr[start];
}

std::string Queue::print_debug_str() { 
    std::string tmp = "start-->"; 
    
    if(!is_empty()) { 
        if(start < end) {
            for(int i = start; i < end; i++) { 
                tmp = tmp + std::to_string(arr[i]) + "-->";
            }
        } else { 
            for(int i = start; i < SIZE; i++) {
                tmp = tmp + std::to_string(arr[i]) + "-->";
            }

            for(int j = 0; j < end; j++) {
                tmp = tmp + std::to_string(arr[j]) + "-->";
            }
        }
    }
    

    tmp = tmp + "end";

    return tmp; 
}