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
    TreeNode *solve(vector<int> &inorder, int inSt, int inEn, vector<int> &postorder, int posSt, int posEn, unordered_map<int, int> &hm)
    {
        if (inSt > inEn || posSt > posEn)
            return NULL;
        int ind = hm[postorder[posEn]];
        int NumLeft = ind - inSt;
        TreeNode *root = new TreeNode(postorder[posEn]);
        root->left = solve(inorder, inSt, ind - 1, postorder, posSt, posSt + NumLeft - 1, hm);
        root->right = solve(inorder, ind + 1, inEn, postorder, posSt + NumLeft, posEn - 1, hm);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = postorder.size();
        unordered_map<int, int> hm;
        for (int i = 0; i < n; i++)
            hm[inorder[i]] = i;
        return solve(inorder, 0, n - 1, postorder, 0, n - 1, hm);
    }
};