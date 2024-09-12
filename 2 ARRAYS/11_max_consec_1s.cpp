#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int curr = 0, maxi = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i])
                curr++;
            else
            {
                curr = 0;
            }
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};