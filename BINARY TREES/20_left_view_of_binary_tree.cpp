// Code with Vinay
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
// Method 1:
class Solution
{
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if (root == NULL)
            return;
        if (res.size() == level)
            res.push_back(root->val);
        recursion(root->left, level + 1, res);
        recursion(root->right, level + 1, res);
    }

    vector<int> leftSideView(TreeNode *root)
    {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(H)       (H -> Height of the Tree)

// Method 2:
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
vector<int> leftView(Node *root)
{
    vector<int> v;
    if (root == NULL)
        return v;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        v.push_back(temp->data);
        int n = q.size();
        // n need to declared outside as it is changing everytime
        for (int i = 0; i < n; i++)
        {
            temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return v;
    //   time complexity: 0(N) as it checks every node
    //   space complexity: 0(N) space for nodes in queue
}