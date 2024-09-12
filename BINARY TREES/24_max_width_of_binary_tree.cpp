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
  int widthOfBinaryTree(TreeNode *root)
  {
    if (root == NULL)
      return 0;
    int ans = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
      int size = q.size();
      int curMin = q.front().second;
      int leftMost, rightMost;
      for (int i = 0; i < size; i++)
      {
        int cur_id = q.front().second - curMin;
        TreeNode *temp = q.front().first;
        q.pop();
        if (i == 0)
          leftMost = cur_id;
        if (i == size - 1)
          rightMost = cur_id;
        if (temp->left != NULL)
          q.push({temp->left, (long long)cur_id * 2 + 1});
        if (temp->right != NULL)
          q.push({temp->right, (long long)cur_id * 2 + 2});
      }
      ans = max(ans, rightMost - leftMost + 1);
    }
    return ans;
  }
};