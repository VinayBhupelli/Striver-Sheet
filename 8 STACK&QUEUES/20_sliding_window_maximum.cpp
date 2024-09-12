#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        int left = 0, right = 0;
        int n = nums.size();
        deque<int> dq;

        while (right < n)
        {
            // remove all the less values than present value
            // since they are not required
            while (!dq.empty() && nums[right] > dq.back())
                dq.pop_back();
            // add this to check in the future
            // as it is the present max
            dq.push_back(nums[right]);
            // updating the window
            if (right - left + 1 == k)
            {
                // this will give the present high value
                // after removing all the less values
                // with the current element
                result.push_back(dq.front());
                // removing if the highest value is the present
                // element and second max element gets updated
                if (dq.front() == nums[left])
                    dq.pop_front();

                left++;
            }
            right++;
        }
        return result;
    }
};