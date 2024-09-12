// bool check(Node){
//     if(Node==NULL)
//         return true;
//     lh= findHleft(Node->left);
//     rh= findHRight(Node->right);
//     if(abs(rh-lh)>1)
//         return false;
//     bool left=check(Node->left);
//     bool right=check(Node->right);

//     if(!left || !right)
//         return false;
//     return true;
// // time complexity: 0(N)*0(N) eachnode*height

// }

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    node *left;
    node *right;
    node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

int height_r(node *root)
{
    if (root == NULL)
        return 0;
    return max(height_r(root->left), height_r(root->right)) + 1;
    // time complexity: 0(n) reach all nodes
}

bool isbalanced(node *root)
{ // naive soln 0(n^2)
    if (root == NULL)
        return true;
    int lf = height_r(root->left);
    int rt = height_r(root->right);
    return (abs(lf - rt) <= 1 && isbalanced(root->left) && isbalanced(root->right));
    // time complexity :0(n^2) cause for each node height function is called so 0(n)*o(n)~0(n^2)
}

int isbalanced_M2(node *root)
{
    if (root == NULL)
        return 0;
    int lf = isbalanced_M2(root->left);
    if (lf == -1)
        return -1;
    int rt = isbalanced_M2(root->right);
    if (rt == -1)
        return -1;
    if (abs(lf - rt) > 1)
        return -1;
    else
        return max(lf, rt) + 1;

    // time complexity :0(n) we traverse every node exactly once and we do constant amount of work
}