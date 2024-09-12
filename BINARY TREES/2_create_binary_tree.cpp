// Code with Vinay
#include<bits/stdc++.h>
using namespace std;

// Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node* tree_make(Node* root,vector<int> &arr,int i){
    if(i>=arr.size())
        return NULL;
    root=new Node(arr[i]);

    root->left=tree_make(root->left,arr,2*i+1);
    root->right=tree_make(root->right,arr,2*i+2);

    return root;
}
Node* createTree(vector<int>&arr){
    int N=arr.size();
    Node* root=NULL;

    return tree_make(root,arr,0);
}