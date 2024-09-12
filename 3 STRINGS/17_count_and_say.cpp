#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string expanding(string s)
    {
        string result = "";
        int count = 0;
        char prev = s[0];
        for (int i = 0; i < s.size(); i++)
        {
            if (prev == s[i])
            {
                count++;
            }
            else
            {
                result += to_string(count);
                result.push_back(prev);
                prev = s[i];
                count = 1;
            }
        }
        result += to_string(count);
        result.push_back(prev);
        return result;
    }
    string onedigit(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        string num = onedigit(n - 1);
        string expand = expanding(num);
        return expand;
    }
    string countAndSay(int n)
    {
        return onedigit(n);
    }
};