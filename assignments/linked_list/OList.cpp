#include "OList.h"
#include <string>
#include <iostream>

OList::OList() { 
    this->head = nullptr; 
}

OList::~OList() { 
    ONode *trailer;
    while(head != nullptr) {
        trailer = head;
        head = head->getNext();
        delete trailer;
    }
}

void OList::insert(int data) { 
    ONode *walker = head; 
    ONode *trailer = nullptr;
    ONode *tmp = new ONode(data);

    // base case: if head doesn't have any data, set first point as tmp
    if(head == nullptr) { 
        tmp->setNext(head);
        head = tmp;
        return;
    } 

    // second base case: if head has only 1 data point, place point at correct position
    if(head->getNext() == nullptr && head->getData() > data) { 
        tmp->setNext(head);
        head = tmp;
        return;
    } else if(head->getNext() == nullptr && head->getData() < data) { 
        head->setNext(tmp);
        return;
    }

    bool reversed = false;
    if(head && head->getNext()) {
        if(head->getData() >= head->getNext()->getData() && head->getData() != head->getNext()->getData()) {
            // this->reverse();
            reversed = true;
        }
    }

    // NEED TO FIX WHEN LIST IS REVERSED AND TRYING TO INSERT VALUES INTO THE LIST, INSERTS AT THE INCORRECT PLACE

    while(walker) { 
        if(trailer && trailer->getData() <= data && walker->getData() >= data || trailer && reversed && trailer->getData() >= data && walker->getData() <= data) {
            trailer->setNext(tmp);
            tmp->setNext(walker);
            return;
        }

        trailer = walker;
        walker = walker->getNext();
    }

    if(reversed && head->getData() <= data || head->getData() >= data && !reversed) { 
        tmp->setNext(head);
        head = tmp;
        return;
    }

    trailer->setNext(tmp);
}

std::string OList::toString() { 
    ONode *walker = head; 
    std::string tmp = "head ---> ";

    while(walker) { 
        tmp = tmp + std::to_string(walker->getData()) + " ---> ";
        walker = walker->getNext();
    }

    tmp = tmp + "null";

    return tmp;
}

bool OList::contains(int value) { 
    ONode *walker = head;

    while(walker) { 
        if(walker->getData() == value) {
            return true;
        }

        walker = walker->getNext();
    }

    return false;
}

int OList::get(int location) { 
    int counter = 0; 
    ONode *walker = head;

    while(walker) { 
        if(counter == location) { 
            return walker->getData();
        }

        counter++;
        walker = walker->getNext();
    }

    return -1;
}

void OList::reverse() { 
    if(head == nullptr || head && head->getNext() == nullptr) {
        throw std::out_of_range("Cannot reverse");
    }

    ONode *walker = head;
    OList *list = new OList();
    ONode *setter = nullptr;     

    list->insert(walker->getData());
    walker = walker->getNext();
    ONode *tmp = new ONode(walker->getData());

    while(walker) { 
        tmp = new ONode(walker->getData());

        tmp->setNext(list->head);
        list->head = tmp;

        walker = walker->getNext();

    }

    head = list->head;
}

void OList::remove(int location) { 
    bool reversed = false;
    if(head && head->getNext()) {
        if(head->getData() >= head->getNext()->getData() && head->getData() != head->getNext()->getData()) {
            reversed = true;
        }
    }

    ONode *walker = head; 
    ONode *t = nullptr; 

    while(location > 0 && walker) { 
        t = walker;
        walker = walker->getNext();
        location--;
    }

    if(walker == nullptr || location < 0) {
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