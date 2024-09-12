#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    // find the count of left side each time and compare with
    void solve(TreeNode *root, int k, int &counter, int &res)
    {
        if (root == NULL)
            return;
        solve(root->left, k, counter, res);
        counter++;
        if (counter == k)
        {
            res = root->val;
            return;
        }
        solve(root->right, k, counter, res);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int counter = 0, res = 0;
        solve(root, k, counter, res);
        return res;
    }
};