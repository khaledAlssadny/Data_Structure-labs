#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

class LinkedList
{

  Node *head;
  LinkedList()
  {
    head = nullptr;
  }
};