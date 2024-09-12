#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
private:
    // pq -> minHeap of K keeps kth largest element as top
    priority_queue<int, vector<int>, greater<int>> pq;
    int len;

public:
    KthLargest(int k, vector<int> &nums)
    {
        len = k;
        for (auto x : nums)
            pq.push(x);
        while (pq.size() > k)
            pq.pop();
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > len)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */