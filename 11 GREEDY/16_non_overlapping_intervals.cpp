#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comp(const vector<int> &v1, const vector<int> &v2)
    {
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // the idea is sort according to there end time
        sort(intervals.begin(), intervals.end(), comp);
        int end = intervals[0][1];
        int count = 0;
        int N = intervals.size();
        for (int i = 1; i < N; i++)
        {
            if (intervals[i][0] >= end)
            {
                end = intervals[i][1];
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};