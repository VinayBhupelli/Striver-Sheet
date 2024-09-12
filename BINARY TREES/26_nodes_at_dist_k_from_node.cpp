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
    void makeParentChild(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &pclink)
    {
        queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty())
        {
            TreeNode *node = qu.front();
            qu.pop();
            if (node->left != NULL)
            {
                pclink[node->left] = node;
                qu.push(node->left);
            }
            if (node->right != NULL)
            {
                pclink[node->right] = node;
                qu.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        // make child assigned to parent
        unordered_map<TreeNode *, TreeNode *> pclink;
        makeParentChild(root, pclink);
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> qu;
        qu.push(target);
        visited[target] = true;
        int dist = 0;
        while (!qu.empty())
        {
            int size = qu.size();
            if (dist == k)
                break;
            dist++;
            while (size--)
            {
                TreeNode *temp = qu.front();
                qu.pop();
                if (pclink.find(temp) != pclink.end() && !visited[pclink[temp]])
                {
                    visited[pclink[temp]] = true;
                    qu.push(pclink[temp]);
                }
                if (temp->left != NULL && !visited[temp->left])
                {
                    visited[temp->left] = true;
                    qu.push(temp->left);
                }
                if (temp->right != NULL && !visited[temp->right])
                {
                    visited[temp->right] = true;
                    qu.push(temp->right);
                }
            }
        }
        vector<int> res;
        while (!qu.empty())
        {
            TreeNode *temp = qu.front();
            qu.pop();
            res.push_back(temp->val);
        }
        return res;
    }
};