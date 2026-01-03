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

int main()
{
  Stack s;
  int n, value;

  cout << "How many elements do you want to push? ";
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cout << "Enter value: ";
    cin >> value;
    s.Push(value);
  }

  cout << "\nPopping all elements:\n";

  int popped;
  while ((popped = s.Pop()) != -1)
  {
    cout << popped << endl;
  }

  return 0;
}
