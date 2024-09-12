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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return new TreeNode(val);

        TreeNode *parent = NULL;
        TreeNode *trasRoot = root;
        while (trasRoot != NULL)
        {
            parent = trasRoot;
            if (trasRoot->val < val)
                trasRoot = trasRoot->right;
            else
                trasRoot = trasRoot->left;
        }
        if (parent->val > val)
            parent->left = new TreeNode(val);
        else
            parent->right = new TreeNode(val);
        return root;
    }
};