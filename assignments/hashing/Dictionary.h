#pragma once
#include "Person.h"
#include "List.h"

class Dictionary { 
    public:
        Dictionary();

        int hash(Person *p);

        void enter(Person *data);
        void enter(std::string first, std::string last, int num);
        Person* retrieve(std::string first, std::string last);
        std::string getKeys();

        // ~Dictionary();
    private:
        List *table[10];

};