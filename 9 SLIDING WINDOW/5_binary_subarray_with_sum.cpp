#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int totalcount = 0;
        int prefixsum = 0;
        unordered_map<int, int> hm;
        hm[0] = 1;
        for (auto x : nums)
        {
            prefixsum += x;
            if (hm.find(prefixsum - goal) != hm.end())
                totalcount += hm[prefixsum - goal];
            hm[prefixsum]++;
        }
        return totalcount;
    }
};