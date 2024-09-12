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
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "";
        queue<TreeNode *> qu;
        qu.push(root);
        string str = "";
        while (!qu.empty())
        {
            TreeNode *temp = qu.front();
            qu.pop();
            if (temp == NULL)
                str.append("#,");
            else
                str.append(to_string(temp->val) + ',');
            if (temp != NULL)
            {
                qu.push(temp->left);
                qu.push(temp->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        stringstream str(data);
        string res;
        getline(str, res, ',');
        TreeNode *root = new TreeNode(stoi(res));
        queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty())
        {
            TreeNode *temp = qu.front();
            qu.pop();
            // for left
            getline(str, res, ',');
            if (res == "#")
            {
                temp->left = NULL;
            }
            else
            {
                TreeNode *left = new TreeNode(stoi(res));
                temp->left = left;
                qu.push(left);
            }
            // for right
            getline(str, res, ',');
            if (res == "#")
            {
                temp->right = NULL;
            }
            else
            {
                TreeNode *right = new TreeNode(stoi(res));
                temp->right = right;
                qu.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));