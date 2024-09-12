#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
public:
    Node *makeParentChild(Node *root, unordered_map<Node *, Node *> &pclink, int target)
    {
        queue<Node *> qu;
        qu.push(root);
        Node *temp;
        while (!qu.empty())
        {
            Node *node = qu.front();
            qu.pop();
            if (node->data == target)
                temp = node;
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
        return temp;
    }
    int minTime(Node *root, int target)
    {
        unordered_map<Node *, Node *> pclink;
        Node *infected = makeParentChild(root, pclink, target);

        unordered_map<Node *, bool> visited;
        queue<Node *> qu;
        qu.push(infected);
        visited[infected] = true;
        int time = 0;
        while (!qu.empty())
        {
            int size = qu.size();
            time++;
            while (size--)
            {
                Node *temp = qu.front();
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
        return time - 1;
    }
};