#include <iostream>
#include "Node.h"
#include "BSTree.h"

/* SETUP TREE 
            10
        5         20
    3      7   15     30
                          40
*/

int main(int argc, char const *argv[]) {
    /* 
     * BSTree video assignment: 
     *
     * Node *root = new Node(10);
     * Node *n2 = new Node(20);
     * Node *n3 = new Node(50);
     * 
     * root->setLeft(n2);
     * root->setRight(n3);
     * 
     * std::cout << root->getData() << std::endl;
     * std::cout << root->getLeft()->getData() << std::endl;
     * std::cout << root->getRight()->getData() << std::endl;
     * 
     * Node *n4 = new Node(30);
     * Node *n5 = new Node(40);
     * 
     * n2->setLeft(n4);
     * n4->setLeft(n5);
     * 
     * std::cout << root->getLeft()->getLeft()->getData() << std::endl;
     * std::cout << root->getLeft()->getLeft()->getLeft()->getData() << std::endl;
     * 
     * Node *n6 = new Node(60);
     * Node *n7 = new Node(70);
     * 
     * n3->setLeft(n6);
     * n3->setRight(n7);
     * 
     * std::cout << root->getRight()->getLeft()->getData() << std::endl;
     * std::cout << root->getRight()->getRight()->getData() << std::endl;
    */

    BSTree *t = new BSTree();
    t->setup();
    std::cout << "Tree from setup func: " << t->get_debug_string() << std::endl;
    std::cout << "==========================================================\n" << std::endl;

    std::cout << "Inserting 200 twice: ";
    t->insert(200);
    std::cout << t->get_debug_string() << std::endl;

    try {
        t->insert(200);
    } catch(int e) {
        std::cout << "Error code:\033[31m " << std::to_string(e) << "\033[0m" << std::endl;
    }

    std::cout << "==========================================================\n" << std::endl;



    return 0;
}
