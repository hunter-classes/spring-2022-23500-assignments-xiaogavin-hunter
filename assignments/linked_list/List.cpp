#include <iostream> 

#include "List.h"

List::List() { 
    head = nullptr;
}

List::~List() { 
    Node *trailer;
    while(head != nullptr) {
        trailer = head;
        head = head->getNext();
        delete trailer;
    }
}

void List::insert(std::string data) { 
    // create a new node 
    Node *new_node = new Node(data); 

    // insert new node 
    new_node->setNext(head);
    head = new_node;
}

void List::insert(int loc, std::string data) { 
    Node *tmp = new Node(data);     
    Node *walker = head; 
    Node *t = nullptr; 

    while(loc > 0 && walker) { 
        t = walker;
        walker = walker->getNext();
        loc--;
    }

    if(loc > 0) {
        throw std::out_of_range("Out of bounds");
    }

    if(!t) { 
        tmp->setNext(walker);
        head = tmp;
    } else { 
        tmp->setNext(walker);
        t->setNext(tmp);
    }
}

std::string List::toString() { 
    // if(head == nullptr) { 
    //     return "";
    // }

    Node *walker = head; 
    std::string s = "";
    while(walker != nullptr) { 
        s = s + walker->getData() + "-->";
        walker = walker->getNext();
    }

    s = s + "nullptr";

    return s; 
}

int List::locate(std::string data) { 
    int location = 0; 
    Node *walker = head; 

    while(walker != nullptr) { 
        if(walker->getData() == data) { 
            return location; 
        }

        location++; 
        walker = walker->getNext();
    }

    return -1;
}

// void List::remove(int location) { 
//     if(location < 0) { 
//         return;
//     }

//     // Node *temp = nullptr; 
//     // Node *walker = head; 
//     // int counter = 0;
//     // Node *temp_node = nullptr;

//     // Node *new_node = new Node(data); 
//     // insert new node 

//     // new_node->setNext(head);
//     // head = new_node;

//     for(int i = 0; i < 2; i++) { 
//         Node *walker = head; 
//         int counter = 0;
//         Node *temp_node = nullptr;

//         while(walker != nullptr) { 
//         if(counter != location) { 
//              // new_node->setNext(head);
//             // head = new_node;
//             Node *new_node = new Node(walker->getData());

//             // temp_node = new Node(walker->getData());
//             // temp_node->setNext(walker->getNext());

//             new_node->setNext(temp_node);
//             temp_node = new_node;
//         }

//         counter++;
//         walker = walker->getNext();
//     }

//     head = temp_node;
//     }   
// }

void List::remove(int location) { 
    // Node *tmp = new Node(data);     
    Node *walker = head; 
    Node *t = nullptr; 

    while(location > 0 && walker) { 
        t = walker;
        walker = walker->getNext();
        location--;
    }

    if(walker == nullptr) {
        throw std::out_of_range("Out of bounds");
    }

    if(!t) { 
        head = walker->getNext();
        delete walker;
    } else { 
        t->setNext(walker->getNext());
        delete(walker);
    }
}