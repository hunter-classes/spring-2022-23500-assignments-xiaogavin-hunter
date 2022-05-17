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

Person* Dictionary::retrieve(std::string first, std::string last) {
    Person *data = new Person(first, last, 0);
    int hash_number = hash(data);
    Node *walker = table[hash_number]->getHead();

    while(walker) {
        if(walker->getPerson()->get_name() == data->get_name()) {
            return walker->getPerson();
        }

        walker = walker->getNext();
    }

    return nullptr;
}

std::string Dictionary::getKeys() {
    std::string keys = ""; 
    for(int i = 0; i < 8; i++) {
        Node *tmp = table[i]->getHead();

        while(tmp) { 
            keys += tmp->getData() + " | ";
            tmp = tmp->getNext();
        }
    }

    return keys;
}