#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

// #include "Node.h"
// #include "List.h"

#include "OList.h"

int main(int argc, char *argv[]) {

    OList *list = new OList();

    list->insert(1);
    list->insert(-1);
    list->insert(0);
    list->insert(-5);
    list->insert(4);
    list->insert(2);
    list->insert(10);
    list->insert(124);
    list->insert(1);
    list->insert(6);
    list->insert(-4);
    list->insert(-1);

    std::cout << list->toString() << std::endl;

    std::string tmp = list->contains(1) ? "true" : "false";
    std::cout << "list contains 1: " << tmp << std::endl;
    tmp = list->contains(1000) ? "true" : "false";
    std::cout << "list contains 1000: " << tmp << std::endl;

    std::cout << list->get(11) << std::endl;

    list->reverse();
    std::cout << list->toString() << std::endl;

    list->insert(14124);
    list->insert(5);
    list->insert(-5);
    std::cout << list->toString() << std::endl;
    
    list->reverse();
    list->remove(1);
    std::cout << list->toString() << std::endl;
    return 0;
}