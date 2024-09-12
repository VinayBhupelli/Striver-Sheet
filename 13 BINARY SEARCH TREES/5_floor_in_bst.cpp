#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
class Solution
{

public:
    int floor(Node *root, int x)
    {
        if (root == NULL)
            return -1;
        int val = -1;
        while (root != NULL)
        {
            if (root->data == x)
                return x;
            if (root->data < x)
            {
                val = root->data;
                root = root->right;
            }
            else
                root = root->left;
        }
        return val;
    }
};