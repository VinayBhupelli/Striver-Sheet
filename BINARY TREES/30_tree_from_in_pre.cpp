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
    TreeNode *solve(vector<int> &inorder, int inSt, int inEn, vector<int> &preorder, int preSt, int preEn, unordered_map<int, int> &hm)
    {
        if (inSt > inEn || preSt > preEn)
            return NULL;
        int ind = hm[preorder[preSt]];
        int NumLeft = ind - inSt;
        TreeNode *root = new TreeNode(preorder[preSt]);
        root->left = solve(inorder, inSt, ind - 1, preorder, preSt + 1, preSt + NumLeft, hm);
        root->right = solve(inorder, ind + 1, inEn, preorder, preSt + NumLeft + 1, preEn, hm);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        unordered_map<int, int> hm;
        for (int i = 0; i < n; i++)
            hm[inorder[i]] = i;
        return solve(inorder, 0, n - 1, preorder, 0, n - 1, hm);
    }
};