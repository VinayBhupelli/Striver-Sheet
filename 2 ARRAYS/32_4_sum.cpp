#include <bits/stdc++.h>
using namespace std;

// same 3 approches as 3SUM
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            // remove duplicates
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                // remove duplicates
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                // get remaining elements
                int k = j + 1, l = n - 1;
                while (k < l)
                {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                    if (sum < target)
                        k++;
                    else if (sum > target)
                        l--;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++, l--;
                        // remove duplicates
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                }
            }
        }
        return ans;
    }
};