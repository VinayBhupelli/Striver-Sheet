#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Node
    {
        int data;
        int i;
        int j;
        Node(int data, int a, int b)
        {
            this->data = data;
            i = a;
            j = b;
        }
    };
    struct compare
    {
        bool operator()(const Node *a, const Node *b) const
        {
            return a->data > b->data;
        }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node *, vector<Node *>, compare> pq;
        vector<int> ans;

        for (int i = 0; i < K; i++)
        {
            Node *temp = new Node(arr[i][0], i, 0);
            pq.push(temp);
        }
        while (pq.size() > 0)
        {
            Node *temp = pq.top();
            int i = temp->i;
            int j = temp->j;
            ans.push_back(temp->data);
            pq.pop();
            if (j + 1 < arr[i].size())
            {
                Node *temp = new Node(arr[i][j + 1], i, j + 1);
                pq.push(temp);
            }
        }
        return ans;
    }
};