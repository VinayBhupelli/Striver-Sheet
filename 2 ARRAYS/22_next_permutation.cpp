#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int> &nums) {
    // for better
    // next_permutation(nums.begin(),nums.end());

    // optimal solution
    int n = nums.size();
    int index = -1;
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        index = i;
        break;
      }
    }
    // 2 1 5 4 3 0 0
    // 2 3 5 4 1 0 0
    // 2 3 0 0 1 4 5
    if (index == -1) {
      reverse(nums.begin(), nums.end());
    } else {
      for (int i = n - 1; i > index; i--) {
        if (nums[i] > nums[index]) {
          swap(nums[i], nums[index]);
          break;
        }
      }
      reverse(nums.begin() + index + 1, nums.end());
    }
  }
};