#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> replaceWithRank(vector<int> &arr, int N)
    {
        // method 1: using map
        // method 2: using pq
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < N; i++)
            pq.push({arr[i], i});

        vector<int> res(N);
        int i = 1;
        int prev = pq.top().first;
        while (!pq.empty())
        {
            // in the case if they are not same
            if (prev != pq.top().first)
                i++;
            prev = pq.top().first;
            int pos = pq.top().second;
            pq.pop();
            res[pos] = i;
        }

        return res;
    }
};