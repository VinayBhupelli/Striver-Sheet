#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    StockSpanner()
    {
    }
    stack<pair<int, int>> s;
    int next(int price)
    {
        int prev = 1;
        while (!s.empty() && s.top().first <= price)
        {
            prev += s.top().second;
            s.pop();
        }
        s.push({price, prev});
        return prev;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */