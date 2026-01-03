#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

class Stack
{
private:
  Node *TOS;

public:
  Stack()
  {
    TOS = NULL;
  }

  int Push(int d)
  {
    Node *newNode = new Node;
    newNode->data = d;
    newNode->next = TOS;
    TOS = newNode;
    return 1;
  }

  int Pop()
  {
    if (TOS == NULL)
    {
      cout << "Stack is empty" << endl;
      return -1;
    }

    Node *temp = TOS;
    int popped = temp->data;
    TOS = TOS->next;
    delete temp;

    return popped;
  }

  int getTos()
  {
    if (TOS == NULL)
    {
      cout << "Stack is empty" << endl;
      return -1;
    }
    return TOS->data;
  }
};

int main()
{
  Stack s;

  // Push elements into the stack
  s.Push(10);
  s.Push(20);
  s.Push(30);

  // Get top element
  cout << "Top element: " << s.getTos() << endl;

  // Pop elements from the stack
  cout << "Popped: " << s.Pop() << endl;
  cout << "Popped: " << s.Pop() << endl;
  cout << "Popped: " << s.Pop() << endl;

  // Try to pop from empty stack
  cout << "Popped: " << s.Pop() << endl;

  int n, value;

  cout << "How many elements do you want to push? ";
  cin >> n;

  // Push elements
  for (int i = 0; i < n; i++)
  {
    cout << "Enter value: ";
    cin >> value;
    s.Push(value);
  }

  cout << "\nPopping all elements:\n";

  // Pop all elements
  int poppedValue;
  while ((poppedValue = s.Pop()) != -1)
  {
    cout << poppedValue << endl;
  }
  return 0;
}
