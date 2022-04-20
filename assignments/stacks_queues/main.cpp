#include <iostream>
#include <string>

#include "stack.h"
#include "queue.h"

int main() { 
    Queue *queue = new Queue(); 
    std::cout << queue->print_debug_str() << std::endl;
    
    for(int i = 0; i <= 5; i++) { 
        queue->enqueue(i);
        std::cout << queue->print_debug_str() << std::endl;
    }

    for(int i = 0; i < 4; i++) { 
        try {
            queue->enqueue(1);
            std::cout << queue->print_debug_str() << std::endl;
        } catch(int e) { 
            std::cout << "Queue full: Error code: " + std::to_string(e) << std::endl;
        }
    }
    
    

    std::cout << "Dequeue val: " << queue->dequeue() << std::endl;
    std::cout << queue->print_debug_str() << std::endl;
    std::cout << "Dequeue val: " << queue->dequeue() << std::endl; 
    std::cout << queue->print_debug_str() << std::endl;
    std::cout << "Dequeue val: " << queue->dequeue() << std::endl; 
    std::cout << queue->print_debug_str() << std::endl;
    std::cout << "Dequeue val: " << queue->dequeue() << std::endl; 
    std::cout << queue->print_debug_str() << std::endl;
    std::cout << "Dequeue val: " << queue->dequeue() << std::endl; 
    std::cout << queue->print_debug_str() << std::endl;

    try {
        std::cout << "Dequeue val: " << queue->dequeue() << std::endl; 
        std::cout << queue->print_debug_str() << std::endl;
    } catch(int e) { 
        std::cout << "Queue empty: Error code: " + std::to_string(e) << std::endl;
    }

    try {
        std::cout << "Dequeue val: " << queue->dequeue() << std::endl; 
        std::cout << queue->print_debug_str() << std::endl;
    } catch(int e) { 
        std::cout << "Queue empty: Error code: " + std::to_string(e) << std::endl;
    }

    try {
        std::cout << "Dequeue val: " << queue->dequeue() << std::endl; 
        std::cout << queue->print_debug_str() << std::endl;
    } catch(int e) { 
        std::cout << "Queue empty: Error code: " + std::to_string(e) << std::endl;
    }

    try {
        std::cout << "Dequeue val: " << queue->dequeue() << std::endl; 
        std::cout << queue->print_debug_str() << std::endl;
    } catch(int e) { 
        std::cout << "Queue empty: Error code: " + std::to_string(e) << std::endl;
    }

    
    return 0; 
}