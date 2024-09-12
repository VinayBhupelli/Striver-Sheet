#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int score = INT_MIN;
        int n = cardPoints.size();
        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += cardPoints[i];
        score = sum;
        for (int i = k - 1; i >= 0; i--)
        {
            sum += cardPoints[n - k + i] - cardPoints[i];
            score = max(score, sum);
        }
        return score;
    }
};
// [11,49,100,20,86,29,72]
// k=4