
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> vect;
        int i = 0;
        while (i < s.size())
        {
            if (s[i] == ' ')
                i++;
            else
            {
                string temp = "";
                while (i < s.size() && s[i] != ' ')
                {
                    temp += s[i];
                    i++;
                }
                if (temp.size() > 0)
                    vect.push_back(temp);
            }
        }
        string res = "";
        for (int i = vect.size() - 1; i > 0; i--)
        {
            res.append(vect[i]);
            res += ' ';
        }
        if (vect.size() > 0)
            res += vect[0];
        return res;
    }
};