#include <iostream>
#include <string>
using namespace std;

struct QueueNode
{
  float value;
  QueueNode *next;
};

class Queue
{
public:
  QueueNode *head = NULL;

  void insert(float value)
  {
    QueueNode *newNode = new QueueNode;

    if (!newNode)
      return;

    cout << "[Adding " << value << " to queue]" << endl;

    newNode->value = value;
    newNode->next = NULL;

    if (isEmpty())
    {
      head = newNode;
    }
    else
    {
      QueueNode *tail = getTail();
      tail->next = newNode;
    }
    print();
  }

  bool dequeue()
  {
    if (isEmpty())
    {
      cout << "Nothing is popped!" << endl;
      return false;
    }
    QueueNode *first = head;
    cout << first->value << " is dequeued" << endl;
    head = head->next;
    delete first;
  }

  void print()
  {
    cout << "Queue: ";

    if (isEmpty())
    {
      cout << "Queue is empty" << endl;
      return;
    }

    QueueNode *ptr = head;
    while (ptr != NULL)
    {
      cout << ptr->value << " ";
      ptr = ptr->next;
    }
    cout << endl;
  }

  ~Queue()
  {
    cout << endl;
    cout << "Calling destructor" << endl;
    while (!isEmpty())
    {
      dequeue();
    }
  }

private:
  QueueNode *getTail()
  {
    if (isEmpty())
    {
      cout << "Queue is empty" << endl;
      return head;
    }
    QueueNode *ptr = head;
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    return ptr;
  }

  bool isEmpty()
  {
    if (!head)
    {
      return true;
    }
    return false;
  }
};

int main()
{
  Queue newQueue;
  float data[] = {10, 8.1f, 7, 3};
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
  {
    newQueue.insert(data[i]);
  }
  newQueue.dequeue();
  newQueue.print();

  return 0;
}
