#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruits(int N, vector<int> &fruits)
    {
        int left = 0, right = 0;
        int len = 0;

        unordered_map<int, int> hm;
        while (right < N)
        {
            hm[fruits[right]]++;
            while (hm.size() > 2)
            {
                if (hm[fruits[left]] == 1)
                    hm.erase(fruits[left]);
                else
                    hm[fruits[left]]--;
                left++;
            }
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};