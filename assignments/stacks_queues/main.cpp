#include <iostream>
#include <string>

#include "stack.h"
#include "queue.h"

int main() { 
    // Stack *stk = new Stack();
    // stk->push("one");
    // stk->push("two");
    // stk->push("three");

    // std::cout << stk->print() << std::endl;

    // std::cout << stk->print() << std::endl;
    // std::cout << stk->top() << std::endl;
    // stk->pop();

    // std::cout << stk->top() << std::endl;

    // try { 
    //     stk->pop();
    // } catch(int e) { 
    //     std::cout << "Empty stack" << std::endl;
    // }

    // try { 
    //     stk->pop();
    // } catch(int e) { 
    //     std::cout << "Empty stack" << std::endl;
    // }

    // try { 
    //     stk->pop();
    // } catch(int e) { 
    //     std::cout << "Empty stack" << std::endl;
    // }


    // std::cout << stk->is_empty() << std::endl;

    // stk->push("item");

    // std::cout << stk->is_empty() << std::endl;

    Queue *queue = new Queue(); 

    std::cout << queue->print_debug_str() << std::endl;
    return 0; 
}