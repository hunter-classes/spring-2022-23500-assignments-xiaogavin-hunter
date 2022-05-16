#include "Dictionary.h"

Dictionary::Dictionary() { 
    for(int i = 0; i < 10; i++) {
        table[i] = new List();
    }
}

int Dictionary::hash(Person *p) {
    // Hashing for this is last + first leng * 4 % 10

    return ((p->get_first().length() + p->get_last().length()) * 4) % 10;
}

void Dictionary::enter(Person *p) {
    table[this->hash(p)]->insert(p);

    return;
}

void Dictionary::enter(std::string first, std::string last, int id) {
    Person *p = new Person(first, last, id);
    this->enter(p);
    return;
}