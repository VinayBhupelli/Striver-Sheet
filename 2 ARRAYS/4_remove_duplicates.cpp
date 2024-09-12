#include <bits/stdc++.h>
using namespace std;
// given sorted duplicates elements
// Method 1: Use set to find unique elements
int removeDuplicates(int arr[], int n) {
  set<int> set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x : set) {
    arr[j++] = x;
  }
  return k;
}
// Method 2: Use Two Pointers approach
class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    int j = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1]) {
        nums[j] = nums[i];
        j++;
      }
    }
    return j;
  }
};