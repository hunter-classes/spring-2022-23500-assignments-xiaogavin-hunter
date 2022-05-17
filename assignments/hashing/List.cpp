#include <iostream>

#include "List.h"


List::List(){
  head = nullptr;
}

void List::insert(std::string first, std::string last, int num){
  //create a Node
  Person *data = new Person(first, last, num);
  Node *new_node = new Node(data);

  //insert the new node
  new_node->setNext(head);
  head = new_node;
}

void List::insert(Node *n) {
  Person *data = n->getPerson();
  Node *new_node = new Node(data);

  //insert the new node
  new_node->setNext(head);
  head = new_node;
}

void List::insert(Person *data) {
  insert(data->get_first(), data->get_last(), data->get_id());
}

std::string List::toString(){
  std::string s = "";
  Node *walker = head;
  while(walker != nullptr){
    s = s+ walker->getPerson()->get_name() + "-->";
    walker = walker->getNext();

  }
  s = s + "nullptr";
  return s;
}

void List::locate(int location, std::string first, std::string last, int num) {
  int counter = 0;
  Node *walker = head; //traverse list
  Person *data = new Person(first, last, num);
  Node *insertion = new Node(data); //new node to insert

  if(location==0) { //if tring to insert to first location
    insertion->setNext(head); //point the new node to the node head is currently pointing to
    head = insertion; //point the head to the new node (new first item)
    return;
  }

  //traverse to the node right before where we are trying to insert
  while(counter != (location-1) && walker != nullptr) {
    walker = walker->getNext();
    counter++;
  }

  if(walker == nullptr && (counter) < location) {
    throw std::out_of_range("Out of range");
    return;
  }

  insertion->setNext(walker->getNext()); //make the new node point to the old node's next node
  walker->setNext(insertion); //make the node before where we are inserting point to the new node

  return;
}

void List::remove(int location) {
  int counter = 0;
  Node *walker = head;
  //if trying to remove the first node in the list
  if(location == 0) {
    if(walker->getNext() == nullptr) {
      head = nullptr; //if theres only one item in the list head now points to nullptr
    } else {
      walker = walker->getNext(); //or else traverse one node, set head to that node
      head=walker;
    }
    return;
  }

  //traverse to the node right before where we are trying to remove
  while(counter != (location-1) && walker != nullptr) {
    walker = walker->getNext();
    counter++;
  }

  if(walker == nullptr) {
    std::cerr << "Err: Out of Bounds\n";
    return;
  }

  //traverse to the node we are trying to remove
  Node *stroller = walker->getNext();
  if(stroller == nullptr) {
    std::cerr << "Err: Out of Bounds\n";
    return;
  }
  //set the node before the one being removed to the removed nodes next node
  walker->setNext(stroller->getNext());
  stroller->setNext(nullptr); //set the next node for the node thats to be removed to nullptr

  return;
}

Node* List::getHead() {
  return head;
}

List::~List() {
  Node *walker = head;
  while(walker != nullptr) {
    walker->getNext();
    delete walker;
    walker = nullptr;
  }

  head=nullptr;
}
