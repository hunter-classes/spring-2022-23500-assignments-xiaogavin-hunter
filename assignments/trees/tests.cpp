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

    SUBCASE("Checking search on empty tree") { 
        BSTree *empty = new BSTree();
        CHECK_THROWS(empty->search(100));
        CHECK_THROWS(empty->rsearch(100));

        delete empty;
    }
}

TEST_CASE("insert") {
    SUBCASE("Empty tree insert") {
        BSTree *t = new BSTree();
        CHECK(t->get_debug_string() == "");

        t->insert(10);
        CHECK(t->get_debug_string() == "10-->nullptr");

        t->insert(20);
        CHECK(t->get_debug_string() == "10-->20-->nullptr");
        
        t->insert(5);
        CHECK(t->get_debug_string() == "5-->10-->20-->nullptr");

        delete t;
    }

    SUBCASE("Repeating elements") {
        BSTree *t = new BSTree();

        t->insert(10);
        CHECK(t->get_debug_string() == "10-->nullptr");

        CHECK_THROWS(t->insert(10));
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

    SUBCASE("Two childs") { 
        SUBCASE("Test one") { 
            BSTree *t = new BSTree();
            t->setup();
            t->insert(40);
            t->remove(20);

            CHECK(t->get_debug_string() == "3-->5-->7-->10-->15-->30-->40-->nullptr");
            
            delete t;
        }

        SUBCASE("Test two") { 
            BSTree *t = new BSTree();
            t->setup();
            t->insert(40);
            t->remove(10);

            CHECK(t->get_debug_string() == "3-->5-->7-->15-->20-->30-->40-->nullptr");
            
            delete t;
        }

        SUBCASE("Test three") { 
            BSTree *t = new BSTree();
            t->setup();
            t->insert(40);
            t->remove(10);
            t->remove(20);

            CHECK(t->get_debug_string() == "3-->5-->7-->15-->30-->40-->nullptr");
            
            delete t;
        }
    }

    SUBCASE("Removing values not within tree") { 
        BSTree *t = new BSTree();
        t->setup();

        CHECK_THROWS(t->remove(10812));
        CHECK_THROWS(t->remove(-100));

        delete t;
    }
}

TEST_CASE("count_leaves") {
    SUBCASE("Base tree") {
        BSTree *t = new BSTree();
        t->setup();
        CHECK(t->count_leaves() == 4);
        t->insert(40);
        CHECK(t->count_leaves() == 4);
        delete t;
    }

    SUBCASE("Empty tree") {
        BSTree *t = new BSTree();
        CHECK(t->count_leaves() == 0);
        delete t;
    }

    SUBCASE("One side only") {
        BSTree *t = new BSTree();
        t->insert(10);
        t->insert(20);
        t->insert(30);
        t->insert(40);
        t->insert(50);

        CHECK(t->count_leaves() == 1);
        delete t; 
    }

    SUBCASE("Two leaves") {
        BSTree *t = new BSTree();
        t->insert(10);
        t->insert(5);
        t->insert(20);

        CHECK(t->count_leaves() == 2);
        delete t;
    }
}

TEST_CASE("get_height") {
    SUBCASE("Base tree & inserting element") {
        BSTree *t = new BSTree();
        t->setup();
        CHECK(t->get_height() == 3);
        t->insert(40);
        CHECK(t->get_height() == 4);
        delete t;
    }

    SUBCASE("Empty tree") {
        BSTree *t = new BSTree();
        CHECK(t->get_height() == 0);

        delete t;
    }

    SUBCASE("Tree with 1 item") {
        BSTree *t = new BSTree(); 
        t->insert(1);
        CHECK(t->get_height() == 1);

        delete t;
    }

    SUBCASE("Tree with elements only going right") { 
        BSTree *t = new BSTree(); 
        t->insert(10);
        t->insert(20);
        t->insert(30);
        t->insert(40);
        t->insert(50);

        CHECK(t->get_height() == 5);

        delete t; 
    }
}

TEST_CASE("sum of given levels") {
    SUBCASE("Base tree") {
        BSTree *t = new BSTree();
        t->setup();
        t->insert(40);

        CHECK(t->sum_of_given_level(1) == 10);
        CHECK(t->sum_of_given_level(2) == 5 + 20);
        CHECK(t->sum_of_given_level(3) == 3 + 7 + 15 + 30);
        CHECK(t->sum_of_given_level(4) == 40);
        CHECK_THROWS(t->sum_of_given_level(5));

        delete t;
    }

    SUBCASE("Empty tree") {
        BSTree *t = new BSTree();
        CHECK_THROWS(t->sum_of_given_level(1));

        delete t;
    }

    SUBCASE("Right only tree") {
        BSTree *t = new BSTree();
        t->insert(10);
        t->insert(20);
        t->insert(30);
        t->insert(40);
        t->insert(50);

        CHECK(t->sum_of_given_level(1) == 10);
        CHECK(t->sum_of_given_level(2) == 20);
        CHECK(t->sum_of_given_level(3) == 30);
        CHECK(t->sum_of_given_level(4) == 40);
        CHECK(t->sum_of_given_level(5) == 50);
        CHECK_THROWS(t->sum_of_given_level(6));
    }
}