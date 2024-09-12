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
// Using level order and line concept
// level order line concept 
// queue stores (root,line)
// map stores (line,node)
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
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
            mp[line]=it.first->data;
            
            if(it.first->left)
                q.push({it.first->left,line-1});
            if(it.first->right)
                q.push({it.first->right,line+1});
        }
        for(auto x: mp)
            result.push_back(x.second);
        return result;
    }
};
