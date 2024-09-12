// Code with Vinay
#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
        int val;
        TreeNode *left,*right;
        TreeNode(int data){
            val=data;
            left=right=NULL;
        }
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) 
            return 0; 
        
        int lh = maxDepth(root->left); 
        int rh = maxDepth(root->right); 
        
        return 1 + max(lh, rh); 
    }
};
// Time Complexity: O(N) 

// Space Complexity: O(1) Extra Space + O(H) Recursion Stack space, 
// where “H”  is the height of the binary tree.


// int height(struct Node* root)
// {
 
//     // Initialising a variable to count the
//     // height of tree
//     int depth = 0;
 
//     queue<Node*> q;
 
//     // Pushing first level element along with NULL
//     q.push(root);
//     q.push(NULL);
//     while (!q.empty()) {
//         Node* temp = q.front();
//         q.pop();
 
//         // When NULL encountered, increment the value
//         if (temp == NULL) {
//             depth++;
//         }
 
//         // If NULL not encountered, keep moving
//         if (temp != NULL) {
//             if (temp->left) {
//                 q.push(temp->left);
//             }
//             if (temp->right) {
//                 q.push(temp->right);
//             }
//         }
 
//         // If queue still have elements left,
//         // push NULL again to the queue.
//         else if (!q.empty()) {
//             q.push(NULL);
//         }
//     }
//     return depth;
// }
// Time Complexity: O(N)
// Auxiliary Space: O(N)