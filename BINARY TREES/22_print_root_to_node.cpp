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
  void helper(Node *root, vector<vector<int>> &ans, vector<int> &subans)
  {
    if (!root)
      return;
    subans.push_back(root->data);
    helper(root->left, ans, subans);
    helper(root->right, ans, subans);
    if (!root->left and !root->right)
    {
      ans.push_back(subans);
    }
    subans.pop_back();
  }
  vector<vector<int>> Paths(Node *root)
  {
    vector<vector<int>> ans;
    vector<int> subans;
    helper(root, ans, subans);
    return ans;
  }
};