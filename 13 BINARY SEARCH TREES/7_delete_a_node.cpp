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
    TreeNode *predecessor(TreeNode *root)
    {
        TreeNode *parent = NULL;
        while (root != NULL)
        {
            parent = root;
            root = root->right;
        }
        return parent;
    }
    TreeNode *solve(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->val == key)
        {
            if (root->left == NULL)
                return root->right;
            else if (root->right == NULL)
                return root->left;
            TreeNode *pred = predecessor(root->left);
            root->val = pred->val;
            root->left = deleteNode(root->left, root->val);
        }
        else if (root->val < key)
            root->right = solve(root->right, key);
        else
            root->left = solve(root->left, key);
        return root;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        TreeNode *newRoot = solve(root, key);
        return newRoot;
    }
};