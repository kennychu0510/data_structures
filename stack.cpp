#include <iostream>
#include <string>
using namespace std;

// Data type to store nodes of a stack/queue

struct StackNode
{
  float value;
  StackNode *next;
};

class Stack
{
public:
  StackNode *head = NULL;

  void insert(float value)
  {
    StackNode *newNode = new StackNode;

    // check if memory allocation is successful
    if (!newNode)
    {
      cout << "Add new node failed" << endl;
      return;
    }

    cout << "[Adding " << value << " to stack]" << endl;

    // initialize new node with given value
    newNode->value = value;
    if (isEmpty())
    {
      newNode->next = NULL;
    }
    else
    {
      newNode->next = head;
    }

    head = newNode;

    print();
  }

  void print()
  {
    cout << "Stack: ";

    if (isEmpty())
    {
      cout << "Stack is empty" << endl;
      return;
    }

    // Loop through stack and print every value
    StackNode *ptr = head;
    while (ptr != NULL)
    {
      cout << ptr->value << " ";
      ptr = ptr->next;
    }
    cout << endl;
  }

  bool pop()
  {
    if (isEmpty())
    {
      return false;
    }
    StackNode *top = head;
    head = head->next;
    cout << "[" << top->value << " is popped!]" << endl;
    delete top;
    print();
    return true;
  }

  void clear()
  {
    cout << endl << "Clearing stack now..." << endl;
    if (isEmpty())
      return;
    while (head != NULL)
    {
      pop();
    }
  }

  ~Stack() {
    clear();
  }

private:
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
  Stack newStack;
  float data[] = {10, 8.1f, 7, 3};
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
  {
    newStack.insert(data[i]);
  }
  newStack.pop();
  newStack.insert(13.5);
  
  return 0;
}
