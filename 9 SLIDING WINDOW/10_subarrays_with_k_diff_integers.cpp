#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> hm;
        int different = 0;
        int i = 0, j = 0;
        int count = 0;
        while (j < n)
        {
            if (hm[nums[j]] == 0)
                different++;
            hm[nums[j]]++;
            int val = 0;
            if (different == k)
            {
                int l = j + 1;
                while (l < n && hm[nums[l]] > 0)
                {
                    l++;
                }
                count += l - j;
                val = l - j;
            }
            while (different == k)
            {
                hm[nums[i]]--;
                if (hm[nums[i]] == 0)
                {
                    different--;
                }
                if (different == k)
                    count += val;
                i++;
            }
            j++;
        }
        return count;
    }
};

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int sub_with_max_element_k = subarray_with_atmost_k(nums, k);
        int reduced_sub_with_max_k = subarray_with_atmost_k(nums, k - 1);
        return (sub_with_max_element_k - reduced_sub_with_max_k);
    }
    int subarray_with_atmost_k(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        int left = 0, right = 0, ans = 0;
        while (right < nums.size())
        {
            map[nums[right]]++;
            while (map.size() > k)
            {
                map[nums[left]]--;
                if (map[nums[left]] == 0)
                    map.erase(nums[left]);
                left++;
            }
            ans += right - left + 1; // basically the size of subarray;
            right++;
        }
        return ans;
    }
};