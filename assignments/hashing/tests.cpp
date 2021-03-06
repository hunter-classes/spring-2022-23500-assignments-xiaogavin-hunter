#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "Dictionary.h"

TEST_CASE("hash") {
    Dictionary *dict = new Dictionary();
    Person *one = new Person("John", "Smith", 1008484);
    Person *two = new Person("Mary", "Gray", 1008666);
    Person *three = new Person("George", "Brownings", 14884442);
    CHECK(dict->hash(one) == ((one->get_first().length() + one->get_last().length()) * 4) % 10);
    CHECK(dict->hash(two) == ((4 + 4) * 4) % 10);
    CHECK(dict->hash(three) == ((6 + 9) * 4) % 10);

    delete dict; 
}

TEST_CASE("retrieve") {
    Dictionary *dict = new Dictionary(); 
    Person *one = new Person("John", "Smith", 1008484);
    Person *two = new Person("Mary", "Gray", 1008666);
    Person *three = new Person("George", "Brownings", 14884442);
    dict->enter(one);
    dict->enter(two);
    dict->enter(three);

    CHECK(dict->retrieve("John", "Smith")->get_id() == one->get_id());
    CHECK(dict->retrieve("Mary", "Smith") == nullptr);
    CHECK(dict->retrieve("George", "Brownings")->get_id() == three->get_id());
    
    delete dict;
}

TEST_CASE("get_keys") {
    Dictionary *dict = new Dictionary();
    Person *one = new Person("John", "Smith", 1008484);
    Person *two = new Person("Mary", "Gray", 1008666);
    Person *three = new Person("George", "Brownings", 14884442);
    dict->enter(one);
    dict->enter(two);
    dict->enter(three);

    CHECK(dict->getKeys() == "Brownings, George | Gray, Mary | Smith, John | ");
    
    dict->enter("Gavin", "Xiao", 2412441);
    CHECK(dict->getKeys() == "Brownings, George | Gray, Mary | Xiao, Gavin | Smith, John | ");

    delete dict;
}

TEST_CASE("enter") {
    Dictionary *dict = new Dictionary();
    Person *one = new Person("John", "Smith", 1008484);
    Person *two = new Person("Mary", "Gray", 1008666);
    Person *three = new Person("George", "Brownings", 14884442);

    dict->enter(one);
    CHECK(dict->getKeys() == "Smith, John | ");

    dict->enter(two);
    CHECK(dict->getKeys() == "Gray, Mary | Smith, John | ");

    dict->enter(three);
    CHECK(dict->getKeys() == "Brownings, George | Gray, Mary | Smith, John | ");

    dict->enter("Gavin", "Xiao", 2412441);
    CHECK(dict->getKeys() == "Brownings, George | Gray, Mary | Xiao, Gavin | Smith, John | ");

    delete dict;
}