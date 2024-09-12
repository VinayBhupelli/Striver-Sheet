#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        vector<string> bucket(s.size() + 1, "");
        string res;

        // count frequency of each character
        for (char c : s)
            freq[c]++;
        // put character into frequency bucket
        for (auto &it : freq)
        {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        // form descending sorted string
        for (int i = s.size(); i > 0; i--)
        {
            if (!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
};

string frequencySort(string s)
{
    unordered_map<char, int> freq;           // for frequency of characters
    priority_queue<pair<int, char>> maxheap; // maxheap according to frequency of characters
    for (char c : s)
        freq[c]++;
    for (auto it : freq)
        maxheap.push({it.second, it.first}); // heap will be constructed on the basis of frequency
    s = "";
    while (!maxheap.empty())
    {
        s += string(maxheap.top().first, maxheap.top().second); // frequency times the character
        maxheap.pop();
    }
    return s;
}