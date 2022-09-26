#include <iostream>
#include <string>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int _data)
  {
    data = _data;
    left = NULL;
    right = NULL;
  }
};

class Tree
{
public:
  Node *root = NULL;

  void preorder(Node *node)
  {
    if (!node)
      return;

    cout << node->data << " ";

    preorder(node->left);
    preorder(node->right);
  }

  void postorder(Node *node)
  {
    if (!node)
      return;

    postorder(node->left);
    postorder(node->right);

    cout << node->data << " ";
  }

  void inOrder(Node *node)
  {
    if (!node)
      return;

    inOrder(node->left);

    cout << node->data << " ";

    inOrder(node->right);
  }

  ~Tree()
  {
    clear(root);
  }

private:
  void clear(Node *node)
  {
    if (!node)
      return;

    clear(node->left);
    clear(node->right);

    delete node;
  }
};

int main()
{
  Tree tree;
  tree.root = new Node(25);
  tree.root->left = new Node(15);
  tree.root->right = new Node(50);
  tree.root->left->left = new Node(10);
  tree.root->left->right = new Node(22);
  tree.root->right->left = new Node(35);
  tree.root->right->right = new Node(70);
  tree.root->left->left->left = new Node(4);
  tree.root->left->left->right = new Node(12);
  tree.root->left->right->left = new Node(18);
  tree.root->left->right->right = new Node(24);
  tree.root->right->left->left = new Node(31);
  tree.root->right->left->right = new Node(44);
  tree.root->right->right->left = new Node(66);
  tree.root->right->right->right = new Node(90);

  cout << "Preorder Traversal: " << endl;
  tree.preorder(tree.root);
  cout << endl << "25 15 10 4 12 22 18 24 50 35 31 44 70 66 90 <-- Correct Answer" << endl;

  cout << endl << "Postorder Traversal: " << endl;
  tree.postorder(tree.root);
  cout << endl << "4 12 10 18 24 22 15 31 44 35 66 90 70 50 25 <-- Correct Answer" << endl;

  cout << endl << "InOrder Traversal: " << endl;
  tree.inOrder(tree.root);
  cout << endl << "4 10 12 15 18 22 24 25 31 35 44 50 66 70 90 <-- Correct Answer" << endl;

  return 0;
}
