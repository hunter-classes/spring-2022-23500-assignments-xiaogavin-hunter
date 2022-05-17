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

    std::cout << dict->getKeys() << std::endl;

    // Brownings, George| \n\nGray, Mary| \n\n\n\nSmith, John\n

    return 0;
}