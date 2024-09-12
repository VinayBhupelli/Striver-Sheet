#include <bits/stdc++.h>
using namespace std;
// Method 1: n^2 solution check sum each time
vector<int> twoSum(int n, vector<int> &arr, int target)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return {-1, -1};
}
// Method 2: Hasing
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(target - nums[i]) != m.end())
            {
                v.push_back(m[target - nums[i]]);
                v.push_back(i);
                return v;
            }
            m[nums[i]] = i;
        }
        return v;
    }
};
// Method 3: Two Pointer
string TwoSum(int n, vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            return "YES";
        }
        else if (sum < target)
            left++;
        else
            right--;
    }
    return "NO";
}
