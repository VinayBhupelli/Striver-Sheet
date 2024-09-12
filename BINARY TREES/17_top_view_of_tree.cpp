// Code with Vinay
#include<bits/stdc++.h>
using namespace std;

// Using level order and line concept
// level order line concept 
// queue stores (root,line)
// map stores (line,node)

class Node{
    public:
        int data;
        Node *left,*right;
        Node(int val){
            data=val;
            left=right=NULL;
        }
};
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> result;
        if(root==NULL)
            return result;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int line=it.second;
            if(mp.find(line)==mp.end())
                mp[line]=it.first->data;
            if(it.first->left)
                q.push({it.first->left,line-1});
            if(it.first->right)
                q.push({it.first->right,line+1});
        }
        for(auto x:mp)
            result.push_back(x.second);
        
        return result;
    }
// time complexity: 0(N)
// space complexity: 0(N)
// level order traversal is not not used
// as bottom nodes go into map first

};
