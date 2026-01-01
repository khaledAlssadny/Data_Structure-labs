#include <iostream>
using namespace std;

class StudentList
{
private:
  struct Node
  {
    int id;
    string name;
    Node *next;
    Node *prev;
  };

  Node *head;

  // Private function to create node
  Node *createNode(int id, string name)
  {
    Node *newNode = new Node();
    newNode->id = id;
    newNode->name = name;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
  }

public:
  StudentList()
  {
    head = NULL;
  }

  // Add at end
  void addStudent(int id, string name)
  {
    Node *newNode = createNode(id, name);

    if (head == NULL)
    {
      head = newNode;
      return;
    }

    Node *temp = head;
    while (temp->next != NULL)
      temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
  }

  // Insert at position
  void insertAt(int position, int id, string name)
  {
    Node *newNode = createNode(id, name);

    if (head == NULL || position == 1)
    {
      newNode->next = head;
      if (head != NULL)
        head->prev = newNode;
      head = newNode;
      return;
    }

    Node *temp = head;
    int count = 1;

    while (temp->next != NULL && count < position - 1)
    {
      temp = temp->next;
      count++;
    }

    // insert in middle or end
    newNode->next = temp->next;
    if (temp->next != NULL)
      temp->next->prev = newNode;

    temp->next = newNode;
    newNode->prev = temp;
  }

  // Search by ID
  void searchById(int id)
  {
    Node *temp = head;

    while (temp != NULL)
    {
      if (temp->id == id)
      {
        cout << "Student Found:\n";
        cout << "ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        return;
      }
      temp = temp->next;
    }

    cout << "Student not found!\n";
  }

  // Display all
  void display()
  {
    Node *temp = head;
    while (temp != NULL)
    {
      cout << temp->id << " - " << temp->name << endl;
      temp = temp->next;
    }
  }
};

int main()
{
  StudentList list;

  list.addStudent(1, "Ahmed");
  list.addStudent(2, "Ali");

  list.insertAt(2, 3, "Sara");

  list.display();
  cout << endl;
  list.searchById(2);

  return 0;
}
