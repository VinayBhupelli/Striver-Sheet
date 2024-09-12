#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bitManipulation(int num, int i)
    {
        cout << ((num >> (i - 1)) & 1) << " ";
        cout << ((1 << (i - 1)) | num) << " ";
        cout << (~(1 << (i - 1)) & num);
    }
};