#include <bits/stdc++.h>
using namespace std;

// Method 1: n^3 loop
// Method 2: n2 loop and set usage
// Method 3: nlogn soln binary approach
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            // remove duplicates
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            // get remaining elements
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    // remove duplicates
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};