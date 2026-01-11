#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
};

Node *createNode(int value)
{
  Node *newNode = new Node();
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node *insert(Node *root, int value)
{
  if (root == NULL)
  {
    return createNode(value);
  }

  if (value < root->data)
  {
    root->left = insert(root->left, value);
  }
  else
  {
    root->right = insert(root->right, value);
  }

  return root;
}

void inorder(Node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

int main()
{
  Node *root = NULL;

  // Insert 1 2 3 4 5
  root = insert(root, 1);
  insert(root, 2);
  insert(root, 3);
  insert(root, 4);
  insert(root, 5);

  cout << "Inorder traversal: ";
  inorder(root);

  return 0;
}
