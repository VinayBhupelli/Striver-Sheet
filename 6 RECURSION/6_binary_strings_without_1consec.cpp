#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

void allbinarystrings(string s, int n)
{
    int len = s.size();
    if (len == n)
    {
        cout << s << endl;
        return;
    }
    if (s[len - 1] == '1')
        allbinarystrings(s + '0', n);
    else
    {
        allbinarystrings(s + '0', n);
        allbinarystrings(s + '1', n);
    }
}
void solve(int n)
{
    string s;
    s.push_back('0');
    allbinarystrings(s, n);
    s[0] = '1';
    allbinarystrings(s, n);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}