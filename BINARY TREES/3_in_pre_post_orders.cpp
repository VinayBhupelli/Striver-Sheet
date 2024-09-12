// Code with Vinay
#include<bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure:

class BinaryTreeNode{
    public :
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
};


void inorder(BinaryTreeNode *root,vector<int>& inorder_array){
    if(root!=NULL){
        inorder(root->left,inorder_array);
        inorder_array.push_back(root->data);
        inorder(root->right,inorder_array);
    }
    
}
void preorder(BinaryTreeNode *root,vector<int>& preorder_array){
    if(root!=NULL){
        preorder_array.push_back(root->data);
        preorder(root->left,preorder_array);
        preorder(root->right,preorder_array);
    }
    
}
void postorder(BinaryTreeNode *root,vector<int>& postorder_array){
    if(root!=NULL){
        postorder(root->left,postorder_array);
        postorder(root->right,postorder_array);
        postorder_array.push_back(root->data);
    }
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode *root){
    vector<vector<int>> allOrders;
    vector<int> inorder_array;
    inorder(root,inorder_array);
    allOrders.push_back(inorder_array);

    vector<int> preorder_array;
    preorder(root,preorder_array);
    allOrders.push_back(preorder_array);
    
    vector<int> postorder_array;
    postorder(root,postorder_array);
    allOrders.push_back(postorder_array);

    return allOrders;
}

// Method 2 
void solve(BinaryTreeNode *root,vector<int>&inord,vector<int>&pre,vector<int>&post){
    if(root==NULL) return;
    pre.push_back(root->data);
    solve(root->left,inord,pre,post);
    inord.push_back(root->data);
    solve(root->right,inord,pre,post);
    post.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode *root){
    // Write your code here.
    vector<int> inord;
    vector<int> pre;
    vector<int> post;
    solve(root,inord,pre,post);
    vector<vector<int>> ans={inord,pre,post};
    return ans;

}