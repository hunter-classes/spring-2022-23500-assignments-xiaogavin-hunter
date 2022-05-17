#include <iostream>
#include "Dictionary.h"

int main() {
    Dictionary *dict = new Dictionary();
    Person *one = new Person("John", "Smith", 1008484);
    Person *two = new Person("Mary", "Gray", 1008666);
    Person *three = new Person("George", "Brownings", 14884442);
    dict->enter(one);
    dict->enter(two);
    dict->enter(three);

    std::cout << "Printing out current dictionary" << std::endl;
    std::cout << dict->getKeys() << std::endl;

    std::cout << "\nAdded Gavin xiao to dictionary" << std::endl;
    dict->enter("Gavin", "Xiao", 2412441);
    std::cout << dict->getKeys() << std::endl;

    std::cout << "\nRetrieving Gavin Xiao from dictionary and printing out id" << std::endl;
    std::cout << dict->retrieve("Gavin", "Xiao")->get_id() << std::endl;

    return 0;
}