#include <iostream>
using namespace std;

class Queue
{
private:
  int arr[5];
  int front, rear;

public:
  Queue()
  {
    front = 0;
    rear = 0;
  }

  // Insert element
  void Enqueue(int d)
  {
    if (rear == 5)
    {
      cout << "Queue is full" << endl;
      return;
    }
    arr[rear] = d;
    rear++;
  }

  // Remove element
  int Dequeue()
  {
    if (front == rear)
    {
      cout << "Queue is empty" << endl;
      return -1;
    }
    int deleted = arr[front];
    front++;
    return deleted;
  }
};

int main()
{
  Queue q;

  q.Enqueue(10);
  q.Enqueue(20);
  q.Enqueue(30);
  q.Enqueue(40);
  q.Enqueue(50);

  // This will print "Queue is full"
  q.Enqueue(60);

  cout << q.Dequeue() << endl; // 10
  cout << q.Dequeue() << endl; // 20

  // Now we can insert again
  q.Enqueue(60);

  q.Enqueue(70); // Queue full again

  return 0;
}
