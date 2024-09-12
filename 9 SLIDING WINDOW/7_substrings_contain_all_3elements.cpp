#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int i = 0, j = 0, n = s.size();
        vector<int> arr(3, 0);
        int ans = 0;
        while (j < n)
        {
            arr[s[j] - 'a']++;
            while (arr[0] && arr[1] && arr[2])
            {
                arr[s[i] - 'a']--;
                i++;
            }
            ans += i;
            j++;
        }
        return ans;
    }
};