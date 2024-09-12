#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
  int val;
  TreeNode *left, *right;
  TreeNode(int data)
  {
    val = data;
    left = right = NULL;
  }
};
class Solution
{
public:
  TreeNode *prev = NULL;
  void flatten(TreeNode *root)
  {
    if (root == NULL)
      return;
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = NULL;
    prev = root;
  }
};

class Solution
{
public:
  void flatten(TreeNode *root)
  {
    if (root == NULL)
      return;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
      TreeNode *curr = st.top();
      st.pop();
      if (curr->right != NULL)
      {
        st.push(curr->right);
      }
      if (curr->left != NULL)
      {
        st.push(curr->left);
      }
      if (!st.empty())
      {
        curr->right = st.top();
      }
      curr->left = NULL;
    }
  }
};

class Solution
{
public:
  void flatten(TreeNode *root)
  {
    if (root == NULL)
      return;
    TreeNode *curr = root;
    while (curr != NULL)
    {
      if (curr->left != NULL)
      {
        TreeNode *temp = curr->left;
        while (temp->right != NULL)
          temp = temp->right;
        temp->right = curr->right;
        curr->right = curr->left;
        curr->left = NULL;
      }
      curr = curr->right;
    }
  }
};