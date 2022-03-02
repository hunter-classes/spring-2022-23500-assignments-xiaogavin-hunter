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
    list->insert(2);
    // list->insert(4);
    // list->insert(6);

    std::cout << list->toString() << std::endl;



    return 0;
}