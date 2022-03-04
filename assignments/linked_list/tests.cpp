#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "OList.h"

//  ---> 

TEST_CASE("Insert") { 
    SUBCASE("Test one, increasing numbers") { 
        OList *list = new OList();
        list->insert(4);
        list->insert(7);
        list->insert(10);
        list->insert(12);

        CHECK(list->toString() == "head ---> 4 ---> 7 ---> 10 ---> 12 ---> null");
        delete list;
    }

    SUBCASE("Test two, decreasing numbers") { 
        OList *list = new OList();
        list->insert(14);
        list->insert(12);
        list->insert(6);
        list->insert(1);
        list->insert(0);

        CHECK(list->toString() == "head ---> 0 ---> 1 ---> 6 ---> 12 ---> 14 ---> null");
        delete list;
    }

    SUBCASE("Test three, random order") { 
        OList *list = new OList();
        list->insert(4);
        list->insert(6);
        list->insert(1);
        list->insert(8);
        list->insert(14);
        list->insert(268);

        CHECK(list->toString() == "head ---> 1 ---> 4 ---> 6 ---> 8 ---> 14 ---> 268 ---> null");
        delete list;
    }

    SUBCASE("Test four, negative numbers") {
        OList *list = new OList();
        list->insert(-14);
        list->insert(120);
        list->insert(5919);
        list->insert(-69291);
        list->insert(5000);

        CHECK(list->toString() == "head ---> -69291 ---> -14 ---> 120 ---> 5000 ---> 5919 ---> null");
        delete list;
    }

    SUBCASE("Test five, repeating numbers") { 
        OList *list = new OList();
        list->insert(5);
        list->insert(5);
        list->insert(6);
        list->insert(6);
        list->insert(-1);
        list->insert(-1);
        list->insert(0);
        list->insert(0);
        list->insert(-1);

        CHECK(list->toString() == "head ---> -1 ---> -1 ---> -1 ---> 0 ---> 0 ---> 5 ---> 5 ---> 6 ---> 6 ---> null");
        delete list;
    }
}

TEST_CASE("toString") {
    SUBCASE("Test one, empty OList") {
        OList *list = new OList();

        CHECK(list->toString() == "head ---> null");
        delete list;
    }
}

TEST_CASE("Contains") {
    SUBCASE("Test one, Empty List") { 
        OList *list = new OList();

        CHECK(list->contains(44) == false);
        CHECK(list->contains(0) == false);
        CHECK(list->contains(-1000) == false);
        delete list;
    }

    SUBCASE("Test two, list with 5 repeating elements") { 
        OList *list = new OList();
        list->insert(-1);
        list->insert(-1);
        list->insert(0);
        list->insert(0);
        list->insert(-1);

        CHECK(list->contains(44) == false);
        CHECK(list->contains(-1) == true);
        CHECK(list->contains(0) == true);
        delete list;
    }

    SUBCASE("Test three, list with 4 different elements") { 
        OList *list = new OList();
        list->insert(120);
        list->insert(5919);
        list->insert(-69291);
        list->insert(5000);

        CHECK(list->contains(120) == true);
        CHECK(list->contains(-1) == false);
        CHECK(list->contains(-10041240) == false);
        CHECK(list->contains(0) == false);
        CHECK(list->contains(5919) == true);
        delete list;
    }
}

TEST_CASE("Get") { 
    SUBCASE("Test one, list with no elements") {
        OList *list = new OList();

        CHECK(list->get(1) == -1);
        CHECK(list->get(0) == -1);
        delete list;
    }

    SUBCASE("Test two, list with repeating elements") {
        OList *list = new OList();
        list->insert(100);
        list->insert(100);
        list->insert(100);
        list->insert(100);
        list->insert(100);
        list->insert(0);
        list->insert(0);

        CHECK(list->get(0) == 0);
        CHECK(list->get(1) == 0);
        CHECK(list->get(2) == 100);
        CHECK(list->get(3) == 100);
        CHECK(list->get(4) == 100);
        CHECK(list->get(5) == 100);
        CHECK(list->get(6) == 100);
        CHECK(list->get(7) == -1);
        delete list;
    }

    SUBCASE("Test three, list with elements, negative get number") {
        OList *list = new OList();
        list->insert(100);
        list->insert(0);

        CHECK(list->get(-1000) == -1);
        CHECK(list->get(-124124119) == -1);
        delete list;
    }

    SUBCASE("Test four, list with random elements") {
        OList *list = new OList();
        list->insert(4);
        list->insert(6);
        list->insert(1);
        list->insert(8);
        list->insert(14);
        list->insert(268);

        CHECK(list->get(0) == 1);
        CHECK(list->get(1) == 4);
        CHECK(list->get(2) == 6);
        CHECK(list->get(3) == 8);
        CHECK(list->get(4) == 14);
        CHECK(list->get(5) == 268);
        CHECK(list->get(6) == -1);
        delete list;
    }
}

TEST_CASE("Remove") {
    SUBCASE("Test one, empty list") {
        OList *list = new OList();
        
        CHECK_THROWS_AS(list->remove(1), std::out_of_range);

        delete list;
    }

    SUBCASE("Test one, empty list") {
        OList *list = new OList();


        delete list;
    }

    SUBCASE("Test one, empty list") {
        OList *list = new OList();


        delete list;
    }

}

