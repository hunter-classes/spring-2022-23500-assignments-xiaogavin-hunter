#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "BSTree.h"

TEST_CASE("Checking to see debug_string") {
    SUBCASE("Setup from classcode: ") { 
        BSTree *t = new BSTree();
        t->setup();
        CHECK(t->get_debug_string() == "3-->5-->7-->10-->15-->20-->30-->nullptr");
        delete t; 
    }

    SUBCASE("Checking resursive search") { 
        BSTree *t = new BSTree();
        t->setup();

        CHECK(t->rsearch(3) == t->search(3));
        CHECK(t->rsearch(5) == t->search(5));
        CHECK_THROWS(t->rsearch(155555));
        delete t; 
    }
}

TEST_CASE("remove") { 
    SUBCASE("Leafs") {
        BSTree *t = new BSTree();
        t->setup();
        t->insert(40);

        CHECK(t->get_debug_string() == "3-->5-->7-->10-->15-->20-->30-->40-->nullptr");

        t->remove(3);
        CHECK(t->get_debug_string() == "5-->7-->10-->15-->20-->30-->40-->nullptr");
        t->remove(7);
        CHECK(t->get_debug_string() == "5-->10-->15-->20-->30-->40-->nullptr");
        t->remove(15);
        CHECK(t->get_debug_string() == "5-->10-->20-->30-->40-->nullptr");
        t->remove(40);
        CHECK(t->get_debug_string() == "5-->10-->20-->30-->nullptr");

        delete t;
    }

    SUBCASE("One child") {
        BSTree *t = new BSTree();
        t->setup();
        t->insert(40);

        t->remove(30);

        CHECK(t->get_debug_string() == "3-->5-->7-->10-->15-->20-->40-->nullptr");
        
        delete t;
    }
}