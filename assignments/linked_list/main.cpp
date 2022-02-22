#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

// #include "Node.h"
#include "List.h"

int main(int argc, char *argv[]) {
    List *l1 = new List(); 
    l1->insert("a");
    l1->insert("b");
    l1->insert("c");
    l1->insert("d");
    l1->insert("e");
    l1->insert("f");
    l1->insert("g");
    l1->insert("h");
    l1->insert("i");


    std::cout << l1->toString() << std::endl;

    std::cout << "a location: " << l1->locate("a") << " | c location: " << l1->locate("c") << " | j location: " << l1->locate("j") << std::endl;

    l1->remove(2);
    std::cout << l1->toString() << std::endl;

    delete l1;
    std::cout << l1->toString() << std::endl;
    return 0;
}