#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int zeros = 0;
        int i = 0;
        int maxi = 0;
        for (int j = 0; j < n; j++)
        {
            if (!nums[j])
                zeros++;
            while (zeros > k)
            {
                if (!nums[i])
                    zeros--;
                i++;
            }
            maxi = max(maxi, j - i + 1);
        }
        return maxi;
    }
};