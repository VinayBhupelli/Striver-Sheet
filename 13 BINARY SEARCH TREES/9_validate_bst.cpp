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
    bool isPossible(TreeNode *root, long long l, long long r)
    {
        if (root == NULL)
            return true;
        if (root->val < r and root->val > l)
        {
            bool val1 = isPossible(root->left, l, root->val);
            bool val2 = isPossible(root->right, root->val, r);
            return val1 && val2;
        }
        return false;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        long long int min = LLONG_MIN, max = LLONG_MAX;
        return isPossible(root, min, max);
    }
};