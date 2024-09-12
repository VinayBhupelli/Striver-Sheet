#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int end = 1;

        int starttime = intervals[0][0];
        int endtime = intervals[0][1];
        while (end < n)
        {
            if (endtime >= intervals[end][0])
            {
                endtime = max(endtime, intervals[end][1]);
                end++;
            }
            else
            {
                res.push_back({starttime, endtime});
                starttime = intervals[end][0];
                endtime = intervals[end][1];
                end++;
            }
        }
        res.push_back({starttime, endtime});
        return res;
    }
};