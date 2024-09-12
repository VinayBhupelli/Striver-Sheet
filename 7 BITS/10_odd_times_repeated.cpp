#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        int val = 0;
        for (int i = 0; i < nums.size(); i++)
            val ^= nums[i];
        return val;
    }
};