#include "OList.h"
#include <string>
#include <iostream>

OList::OList() { 
    this->head = nullptr; 
}

void OList::insert(int data) { 
    ONode *new_node = new ONode(data); 
    if(head == nullptr) { 
        // create a new node 

        // insert new node 
        new_node->setNext(head);
        head = new_node;
    } else { 
        ONode *walker = head; 
        ONode *trailer = nullptr; 

        while(walker) { 
            if(walker->getData() > data && trailer->getData() < data) { 
                new_node->setNext(walker);
                walker->setNext(trailer);

                head = new_node;
                return;
            }

            trailer = walker;
            walker = walker->getNext();

            std::cout << trailer << " " << head << "\n"; 
        }

        if(trailer == head) { 
            
        }
    }
}

std::string OList::toString() { 
    ONode *walker = head; 
    std::string tmp = "";

    while(walker) { 
        tmp = tmp + std::to_string(walker->getData()) + "--->";

        walker = walker->getNext();
    }

    tmp = tmp + "null";

    return tmp;
}