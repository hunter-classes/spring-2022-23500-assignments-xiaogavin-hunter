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

std::string queue_string(int total) { 
    std::string tmp = "start-->";
    for(int i = 0; i <= total; i++) { 
        tmp += std::to_string(i) + "-->";
    }

    tmp += "end";
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

TEST_CASE("Queue class: Enqueue & Full queue") { 
    Queue *q = new Queue(); 
    for(int i = 0; i < 8; i++) {
        q->enqueue(i);
        CHECK(q->print_debug_str() == queue_string(i));
    }

    SUBCASE("Queue is full, should throw") { 
        CHECK_THROWS(q->enqueue(9));
        CHECK_THROWS(q->enqueue(10));
    }

    delete q; 
}

TEST_CASE("Queue class: dequeue & Empty queue") { 
    Queue *q = new Queue(); 

    for(int i = 0; i < 8; i++) { 
        q->enqueue(i);
    }

    for(int i = 0; i < 8; i++) { 
        CHECK(q->dequeue() == i);
    }

    SUBCASE("Queue is empty, should throw") { 
        CHECK_THROWS(q->dequeue());
        CHECK_THROWS(q->dequeue());
    }

    delete q;
}

TEST_CASE("Queue class: front()") {
    Queue *q = new Queue();
    q->enqueue(0);
    CHECK(q->front() == 0);

    for(int i = 1; i < 8; i++) { 
        q->enqueue(i);
    } 

    CHECK(q->front() == 0);
    q->dequeue();
    CHECK(q->front() == 1);

    for(int i = 0; i < 7; i++) { 
        q->dequeue();
    }

    SUBCASE("Empty queue") { 
        CHECK_THROWS(q->front());
        CHECK_THROWS(q->front());
    }

    delete q;
}

TEST_CASE("Queue class: is_empty and is_full") { 
    Queue *q = new Queue(); 
    CHECK(q->is_empty() == true);
    CHECK(q->is_full() == false);

    q->enqueue(0);
    CHECK(q->is_empty() == false);
    CHECK(q->is_full() == false);  

    for(int i = 0; i < 7; i++) { 
        q->enqueue(i);
    }

    CHECK(q->is_empty() == false);
    CHECK(q->is_full() == true);

    delete q;  
}