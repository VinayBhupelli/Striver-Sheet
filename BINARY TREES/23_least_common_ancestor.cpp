// Code with Vinay
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left,*right;
        Node(int val){
            data=val;
            left=right=NULL;
        }
};
// Using null pointer return technique
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
        //check using an examples   
       if(!root)
            return NULL;
        if(root->data==n1 || root->data==n2)
            return root;
            
        Node* leftside=lca(root->left,n1,n2);
        Node* rightside=lca(root->right,n1,n2);
        
        // this means root is parent
        if(leftside!=NULL && rightside!=NULL)
            return root;
            
        // this means parent is present in left side    
        if(leftside!=NULL) 
            return leftside;
        else
        // this means parent is present in right side
            return rightside;
    }
};
