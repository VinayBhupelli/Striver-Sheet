#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // by default it is max heap
        // priority_queue<int> pq;
        //  values stores as 10,9,8,7

        // making it to min heap
        // 7,8,9,10
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++)
        {
            if (pq.top() < nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};