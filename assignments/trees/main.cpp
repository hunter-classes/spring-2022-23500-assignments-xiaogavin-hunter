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
    // Node *root = new Node(10);
    // Node *n2 = new Node(20);
    // Node *n3 = new Node(50);

    // root->setLeft(n2);
    // root->setRight(n3);

    // std::cout << root->getData() << std::endl;
    // std::cout << root->getLeft()->getData() << std::endl;
    // std::cout << root->getRight()->getData() << std::endl;

    // Node *n4 = new Node(30);
    // Node *n5 = new Node(40);

    // n2->setLeft(n4);
    // n4->setLeft(n5);

    // std::cout << root->getLeft()->getLeft()->getData() << std::endl;
    // std::cout << root->getLeft()->getLeft()->getLeft()->getData() << std::endl;

    // Node *n6 = new Node(60);
    // Node *n7 = new Node(70);

    // n3->setLeft(n6);
    // n3->setRight(n7);

    // std::cout << root->getRight()->getLeft()->getData() << std::endl;
    // std::cout << root->getRight()->getRight()->getData() << std::endl;

    BSTree *tree = new BSTree();
    tree->setup(); 
    tree->insert(40);

    std::cout << tree->get_debug_string() << std::endl;
    
    // try {
    //     std::cout << tree->rsearch(1000) << std::endl;
    // } catch(int e) {
    //     std::cout << "Value not found" << std::endl;
    // }

    
    // tree->insert(5000);
    // std::cout << tree->get_debug_string() << std::endl;

    // tree->insert(6);
    // std::cout << tree->get_debug_string() << std::endl;


    // BSTree *tmp = new BSTree();
    // tmp->rinsert(1);
    // tmp->rinsert(5);
    // tmp->rinsert(6);
    
    // try {
    //     tmp->rinsert(7);
    // } catch(int e) {
    //     std::cout << "Error val: " << std::to_string(e) << std::endl;
    // }

    // try {
    //     tmp->rinsert(2);
    // } catch(int e) {
    //     std::cout << "Error val: " << std::to_string(e) << std::endl;
    // }

    // try {
    //     tmp->rinsert(1);
    // } catch(int e) {
    //     std::cout << "Error val: " << std::to_string(e) << std::endl;
    // }

    // std::cout << tmp->get_debug_string() << std::endl;

    // std::cout << tree->treesum() << std::endl;

    // tree->remove(5);

    std::cout << tree->get_height() << std::endl;

    BSTree *small_tree = new BSTree();
    small_tree->insert(10);
    small_tree->insert(20);

    std::cout << small_tree->get_debug_string() << std::endl;
    std::cout << small_tree->get_height() << std::endl;


    BSTree *increasing_only_right = new BSTree();
    increasing_only_right->insert(10);
    increasing_only_right->insert(20);
    increasing_only_right->insert(30);
    increasing_only_right->insert(40);
    increasing_only_right->insert(50);

    std::cout << increasing_only_right->get_debug_string() << std::endl;
    std::cout << increasing_only_right->get_height() << std::endl;



    return 0;
}
