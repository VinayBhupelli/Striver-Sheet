#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int> &nums) {
    int n = nums.size();
    unordered_set<int> st;
    for (int i = 0; i < n; i++) st.insert(nums[i]);

    int maxilen = 0;
    for (int i = 0; i < n; i++) {
      if (st.find(nums[i] - 1) == st.end()) {
        int temp = 1;
        int val = nums[i];
        while (st.find(val + 1) != st.end()) {
          temp++;
          val++;
        }
        maxilen = max(maxilen, temp);
      }
    }
    return maxilen;
  }
};