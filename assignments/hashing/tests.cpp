#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "Dictionary.h"

Person *one = new Person("John", "Smith", 1008484);
Person *two = new Person("Mary", "Gray", 1008666);
Person *three = new Person("George", "Brownings", 14884442);

TEST_CASE("hash") {
    Dictionary *dict;
    CHECK(dict->hash(one) == ((one->get_first().length() + one->get_last().length()) * 4) % 10);
    CHECK(dict->hash(two) == ((4 + 4) * 4) % 10);
    CHECK(dict->hash(three) == ((6 + 9) * 4) % 10);
}

