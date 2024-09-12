#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (j == 0 || asteroids[i] > 0)
                asteroids[j++] = asteroids[i];
            else
            {
                while (j > 0 && asteroids[j - 1] > 0 && abs(asteroids[i]) > asteroids[j - 1])
                {
                    j--;
                }
                if (j > 0 && asteroids[j - 1] > 0 && abs(asteroids[i]) == asteroids[j - 1])
                    j--;
                else if (j == 0 || asteroids[j - 1] < 0)
                    asteroids[j++] = asteroids[i];
            }
        }

        vector<int> res(asteroids.begin(), asteroids.begin() + j);
        return res;
    }
};