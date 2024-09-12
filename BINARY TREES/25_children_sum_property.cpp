#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *left, *right;
  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

class Solution
{
public:
  // Function to check whether all nodes of a tree have the value
  // equal to the sum of their child nodes.
  int check(Node *root, bool &flag)
  {
    if (root == NULL)
      return 0;
    int left = check(root->left, flag);
    int right = check(root->right, flag);

    if (root->left == NULL && root->right == NULL)
      return root->data;
    else if (root->data != left + right)
      flag = true;
    return root->data;
  }
  int isSumProperty(Node *root)
  {
    bool flag = false;
    check(root, flag);
    return !flag;
  }
};