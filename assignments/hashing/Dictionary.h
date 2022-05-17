#pragma once
#include <iostream>
#include "List.h"

class Dictionary{
    private:
        List *table[10];

    public:
        Dictionary();
        ~Dictionary();

        int hash(Person *p);
        void enter(Person *data);
        void enter(std::string first, std::string last, int num);
        Person* retrieve(std::string first, std::string last);
        std::string getKeys();
};
