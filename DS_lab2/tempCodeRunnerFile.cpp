#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

class LinkedList
{
private:
  Node *head;

public:
  LinkedList()
  {
    head = NULL;
  }

  // Allow Stack to access head
  friend class Stack;
};
class Stack
{
private:
  LinkedList list;

public:
  int Push(int d)
  {
    Node *newNode = new Node;
    newNode->data = d;

    newNode->next = list.head;
    list.head = newNode;

    return 1;
  }

  int Pop()
  {
    if (list.head == NULL)
    {
      cout << "Stack is empty" << endl;
      return -1;
    }

    Node *temp = list.head;
    int popped = temp->data;

    list.head = list.head->next;
    delete temp;

    return popped;
  }

  int getTos()
  {
    if (list.head == NULL)
    {
      cout << "Stack is empty" << endl;
      return -1;
    }
    return list.head->data;
  }
};
