#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int n = s.size(), m = goal.size();
        if (n != m)
            return false;
        int start = 0, end = n;
        for (int i = 0; i < n; i++)
        {
            string temp = s.substr(i, end) + s.substr(start, i);
            if (temp == goal)
                return true;
        }
        return false;
    }
};

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
        {
            return false;
        }

        string concatenated = goal + goal;

        return concatenated.find(s) != string::npos;
    }
};