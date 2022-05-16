#pragma once

#include <iostream>
#include "Person.h"

class Node{
private:
  Person *data;
  Node *next;

public:
  Node();
  Node(Person *data);
  Node(std::string first, std::string last, int num);
  Node(Person *data, Node *next);

  void setData(Person *data);
  Person *getPerson();
  void setNext(Node *next);

  std::string getData();
  Node *getNext();
};