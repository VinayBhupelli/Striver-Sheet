#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

// The algorithm approach can be stated as:

// We first take an explicit stack data structure and set an infinite loop.
// In every iteration we check whether our current node is pointing to NULL or not.
// If it is not pointing to null, we simply push the current value to the stack and move the current node to its left child.
// If it is pointing to NULL, we first check whether the stack is empty or not. If the stack is empty, it means that we have traversed the tree and we break out of the loop.
// If the stack is not empty, we pop the top value of the stack, print it and move the current node to its right child.

// Method 1: Iterative
vector < int > inOrderTrav(node * curr) {
  vector < int > inOrder;
  stack < node * > s;
  while (true){
    if (curr != NULL) {
      s.push(curr);
      curr = curr -> left;
    } 
    else{
      if (s.empty()) 
        break;
      curr = s.top();
      inOrder.push_back(curr -> data);
      s.pop();
      curr = curr -> right;
    }
  }
  return inOrder;
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(8);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> right = newNode(10);

  vector < int > inOrder;
  inOrder = inOrderTrav(root);

  cout << "The inOrder Traversal is : ";
  for (int i = 0; i < inOrder.size(); i++) {
    cout << inOrder[i] << " ";
  }
  return 0;
}
// Output: The inOrder Traversal is : 4 2 8 5 1 6 3 9 7 10

// Time Complexity: O(N).
// Reason: We are traversing N nodes and every node is visited exactly once.

// Space Complexity: O(N)
// Reason: In the worst case (a tree with just left children), the space complexity will be O(N).



// Method 2 using recusrion
void inOrderTrav(node * curr, vector < int > & inOrder) {
  if (curr == NULL)
    return;

  inOrderTrav(curr -> left, inOrder);
  inOrder.push_back(curr -> data);
  inOrderTrav(curr -> right, inOrder);
}


int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(8);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> right = newNode(10);

  vector < int > inOrder;
  inOrderTrav(root, inOrder);

  cout << "The inOrder Traversal is : ";
  for (int i = 0; i < inOrder.size(); i++) {
    cout << inOrder[i] << " ";
  }
  return 0;
}

// Output: The inOrder Traversal is : 4 2 8 5 1 6 3 9 7 10 

// Time Complexity: O(N).
// Reason: We are traversing N nodes and every node is visited exactly once.

// Space Complexity: O(N)
// Reason: Space is needed for the recursion stack. 
// In the worst case (skewed tree), space complexity can be O(N).