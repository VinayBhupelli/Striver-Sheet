#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string removeOuterParentheses(string s) {
    int n = s.size();
    string res = "";
    int matched = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(')
        matched++;
      else if (s[i] == ')') {
        matched--;
        if (matched == 0) {
          int len = (i - 1) - (start + 1) + 1;
          if (len > 0) res += s.substr(start + 1, len);
          start = i + 1;
        }
      }
    }
    return res;
  }
};

// More Simplified
class Solution {
 public:
  string removeOuterParentheses(string s) {
    string result;    // To store the final result
    int balance = 0;  // To keep track of the balance of parentheses

    // Iterate through each character in the string
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        // If balance is greater than 0, it means this '(' is not an
        // outermost parenthesis
        if (balance > 0) {
          result += s[i];  // Add the character to the result
        }
        balance++;  // Increase the balance for '('
      } else {
        balance--;  // Decrease the balance for ')'
        // If balance is greater than 0, it means this ')' is not an
        // outermost parenthesis
        if (balance > 0) {
          result += s[i];  // Add the character to the result
        }
      }
    }

    return result;  // Return the final result after removing outermost
                    // parentheses
  }
};
// simplar
class Solution {
 public:
  string removeOuterParentheses(string s) {
    string result;
    int balance = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        balance++;
        if (balance > 1) result += s[i];
      } else {
        balance--;
        if (balance > 0) result += s[i];
      }
    }
    return result;
  }
};