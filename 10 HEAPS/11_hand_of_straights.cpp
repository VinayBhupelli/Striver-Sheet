#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        unordered_map<int, int> countMap;
        for (int card : hand)
            countMap[card]++;
        sort(hand.begin(), hand.end());
        for (int i = 0; i < hand.size(); i++)
        {
            if (countMap[hand[i]] > 0)
                for (int j = 0; j < groupSize; j++)
                {
                    int currCard = hand[i] + j;
                    if (countMap[currCard] == 0)
                        return false;
                    countMap[currCard]--;
                }
        }
        return true;
    }
};