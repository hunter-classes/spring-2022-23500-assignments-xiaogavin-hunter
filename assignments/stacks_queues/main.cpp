#include <iostream>
#include <string>

#include "stack.h"
#include "queue.h"

int main() {
    Stack *s = new Stack();
    std::cout << "Stack should be empty: " << s->is_empty() << std::endl;
    std::cout << "==============================================" << std::endl;

    s->push("one"); 
    s->push("two");
    s->push("three");
    std::cout << "Stack should be three-->two-->one: " << s->print() << std::endl;
    std::cout << "==============================================" << std::endl;

    std::cout << "Top of stack should be three: " << s->top() << std::endl;
    std::cout << "==============================================" << std::endl;

    std::cout << "Removing all items from stack: " << std::endl;
    for(int i = 0; i < 3; i++) {
        std::cout << "Pushing items from stack: " << s->pop() << std::endl;;
    }
    std::cout << "==============================================" << std::endl;

    std::cout << "Trying to pop item from empty stack" << std::endl; 
    try { 
        s->pop();
    } catch(int e) { 
        std::cout << "Empty stack, Error code: " << std::to_string(e) << std::endl;
    }
    
    std::cout << "==============================================" << std::endl << std::endl;

    Queue *q = new Queue(); 
    std::cout << q->print_debug_str() << std::endl;
    std::cout << "Queue is empty: " << q->is_empty() << std::endl; 
    std::cout << "Queue is full: " << q->is_full() << std::endl;
    std::cout << "==============================================" << std::endl;

    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    std::cout << "Should be 1, 2, 3: " << q->print_debug_str() << std::endl;
    std::cout << "Dequeue one item: " << q->dequeue() << std::endl;
    std::cout << q->print_debug_str() << std::endl;
    std::cout << "==============================================" << std::endl;

    for(int i = 4; i <= 9; i++) {
        std::cout << "Enqueueing: " << std::to_string(i) << std::endl; 
        q->enqueue(i);
    }

    std::cout << "Filling up queue: " << q->print_debug_str() << std::endl;
    std::cout << "Queue is empty: " << q->is_empty() << std::endl; 
    std::cout << "Queue is full: " << q->is_full() << std::endl;

    std::cout << "Trying to add one item onto full queue: ";
    try { 
        q->enqueue(10);
    } catch(int e) {
        std::cout << "\nQueue is full: Error code: " << std::to_string(e) << std::endl;
    }
    std::cout << "==============================================" << std::endl;

    std::cout << "Emptying queue: " << std::endl;

    for(int i = 0; i < 8; i++) { 
        std::cout << "Dequeueing:" << q->dequeue() << '\n'; 
    }

    std::cout << "Queue right now: " << q->print_debug_str() << std::endl;
    std::cout << "Queue is empty: " << q->is_empty() << std::endl; 
    std::cout << "Queue is full: " << q->is_full() << std::endl;

    try { 
        std::cout << "Dequeue: " << q->dequeue() << std::endl;
    } catch(int e) {
        std::cout << "\nQueue is empty: Error code: " << std::to_string(e) << std::endl;
    }
    std::cout << "==============================================" << std::endl;


    return 0; 
}