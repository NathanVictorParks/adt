#include <iostream>

using namespace std;

class Node {
 private:
  
 public:
  int data;
  Node* left; 
  Node* right;
  Node();
  Node(int d);
  void operator=(Node in);
  static Node add(int d, Node* start);
  static int sum(Node* in,int sum);
  static int size(Node* in, int result);
};

Node::Node() {
  data = 0;
  left = nullptr;
  right = nullptr;
}
Node::Node(int d) {
  data = d;
  left = nullptr;
  right = nullptr;
}
void Node::operator=(Node in) {
  data = in.data;
  left = in.left;
  right = in.right;
}
Node add(int d, Node* start) {
  Node* tmp= new Node; 
  tmp->data = d;
  if (d < start->data && start->left==nullptr) {
    start->left = tmp;
    return *tmp;
  }
  if (d >= start->data && start->right==nullptr) {

    start->right = tmp;
    return *tmp;
  }
  if (d < start->data && start->left) {
    add(d, start->left);
  }
  if (d >= start->data && start->right) {
    add(d, start->right);
  }
  return false;          
}
int sum(Node* in,int result=0) {
  if (!in->left && !in->right) {
    return in->data + result;  
  }
  if (in->left && in->right) {
    return (in->data + sum(in->left, result) + sum(in->right, result));  
  }
  if (in->left) {
    return (in->data + sum(in->left, result));  
  }
  if (in->right) {
    return (in->data + sum(in->right, result));
  } 
  return 0;  
}
int size(Node* in, int result=0) {
  if (!in->left && !in->right) {
    return 1 + result;  
  }
  if (in->left && in->right) {
    return (1 + size(in->left, result) + size(in->right, result));  
  }
  if (in->left) {
    return (1 + size(in->left, result));  
  }
  if (in->right) {
    return (1 + size(in->right, result));
  }
  return 0;
}

int main() {
  Node* ptr;
  Node root(10);
  Node n1;
  add(10, &root);
  add(9, &root);
  cout << size(&root);

  return 0;
}