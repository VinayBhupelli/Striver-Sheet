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
int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;
    int val = -1;
    while (root != NULL)
    {
        if (root->data == input)
            return input;
        if (root->data < input)
            root = root->right;
        else
        {
            val = root->data;
            root = root->left;
        }
    }
    return val;
}