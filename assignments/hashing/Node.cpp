#include <iostream>
#include "Node.h"

Node::Node(Person *data){
  this->data = data;
  this->next = nullptr;
}

Node::Node(Person *data, Node *next){
  this->data = data;
  this->next = next;
}

Node::Node(std::string first, std::string last, int num) {
  Person *data = new Person(first, last, num);
  this->data = data;
}

void Node::setData(Person *data){
  this->data = data;
}


void Node::setNext(Node *next){
  this->next = next;
}

std::string Node::getData(){
  return this->data->get_name();
}

Person *Node::getPerson(){
  return this->data;
}

Node *Node::getNext(){
  return this->next;
}