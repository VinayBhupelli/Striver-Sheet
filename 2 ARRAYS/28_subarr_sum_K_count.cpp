#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int K)
    {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> hm;
        int N = nums.size();
        for (int i = 0; i < N; i++)
        {
            sum += nums[i];
            if (sum == K)
                count++;

            // sum-K here not K-sum
            int rem = sum - K;
            if (hm.find(rem) != hm.end())
            {
                count += hm[rem];
            }
            hm[sum]++;
        }
        return count;
    }
};