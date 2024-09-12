#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    vector<string> vect;
    int i = 0;
    while (i < s.size()) {
      if (s[i] == ' ')
        i++;
      else {
        string temp = "";
        while (i < s.size() && s[i] != ' ') {
          temp += s[i];
          i++;
        }
        if (temp.size() > 0) vect.push_back(temp);
      }
    }
    string res = "";
    for (int i = vect.size() - 1; i > 0; i--) {
      res.append(vect[i]);
      res += ' ';
    }
    if (vect.size() > 0) res += vect[0];
    return res;
  }
};

// more optimised
class Solution {
 public:
  string reverseWords(string s) {
    // First reverse the string
    reverse(s.begin(), s.end());
    int n = s.size();
    int left = 0;
    int right = 0;
    int i = 0;
    while (i < n) {
      // skip all the empty chars
      while (i < n && s[i] == ' ') i++;
      if (i == n) break;

      // traverse the word
      while (i < n && s[i] != ' ') {
        s[right++] = s[i++];
      }
      // reverse and attach & make pointers correct
      reverse(s.begin() + left, s.begin() + right);
      s[right++] = ' ';
      left = right;
      i++;
    }
    s.resize(right - 1);
    return s;
  }
};
