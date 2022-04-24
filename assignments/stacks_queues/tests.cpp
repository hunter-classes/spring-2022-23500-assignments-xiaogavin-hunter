#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "stack.h"
#include "queue.h"

std::string list_nums[] = { "one", "two", "three", "four", "five" };

std::string stack_string(int total) { 
    std::string tmp = ""; 

    for(int i = 0; i < total; i++) { 
        tmp = list_nums[i] + "-->" + tmp; 
    }

    tmp = tmp + "nullptr";
    return tmp; 
}

TEST_CASE("Stack class: push(item)") { 
    Stack *s = new Stack();
    for(int i = 0; i < 5; i++) { 
        s->push(list_nums[i]);
        CHECK(s->print() == stack_string(i + 1));
    }

    delete s;
}

TEST_CASE("Stack class: pop()") { 
    Stack *s = new Stack();
    for(int i = 0; i < 5; i++) { 
        s->push(list_nums[i]);
    }

    for(int i = 0; i < 5; i++) { 
        CHECK(s->pop() == list_nums[5 - i - 1]); // Checking popped item is first item in list 
        CHECK(s->print() == stack_string(5 - i - 1)); // Checking stack list 
    }
    
    delete s;
}

TEST_CASE("Stack class: top()") { 
    Stack *s = new Stack();
    for(int i = 0; i < 5; i++) { 
        s->push(list_nums[i]);
    }

    CHECK(s->top() == "five");
    s->pop();
    CHECK(s->top() == "four");

    delete s;
}

TEST_CASE("Stack class: Empty stack") {
    Stack *s = new Stack(); 
    s->push("one");
    s->push("two");

    CHECK(s->print() == "two-->one-->nullptr");
    CHECK(s->pop() == "two");
    CHECK(s->pop() == "one");
    
    CHECK_THROWS(s->pop());
    CHECK_THROWS(s->pop());
    CHECK_THROWS(s->top());

    delete s; 
}

TEST_CASE("Queue class: enqueue") { 
    
}