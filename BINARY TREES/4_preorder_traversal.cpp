// Code with Vinay
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

// Method 1: Iterative
vector < int > preOrderTrav(Node * curr) {
  vector < int > preOrder;
  if (curr == NULL)
    return preOrder;

  stack < Node * > s;
  s.push(curr);

  while (!s.empty()) {
    Node * topNode = s.top();
    preOrder.push_back(topNode -> data);
    s.pop();
    if (topNode -> right != NULL)
      s.push(topNode -> right);
    if (topNode -> left != NULL)
      s.push(topNode -> left);
  }
  return preOrder;
    // time complexity : 0(N) to reach all nodes
    // space complexity : 0(N) max nodes stored in stacks
}

// Method 2:Recursion
void preorder(Node *root){
    if (root != NULL){
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    // time complexity : 0(N) to reach all nodes
     // space complexity : 0(N) max recursion stack space