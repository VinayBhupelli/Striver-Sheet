#include <bits/stdc++.h>
using namespace std;
// Method 1: Sort the array
class Solution {
 public:
  void sortColors(vector<int> &nums) { sort(nums.begin(), nums.end()); }
};
// Method 2: Count frequencies
void sortArray(vector<int> &arr, int n) {
  int cnt0 = 0, cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0)
      cnt0++;
    else if (arr[i] == 1)
      cnt1++;
    else
      cnt2++;
  }
  for (int i = 0; i < cnt0; i++) arr[i] = 0;
  for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1;
  for (int i = cnt0 + cnt1; i < n; i++) arr[i] = 2;
}

// Method 3: Dutch National flag algorithm

// didnt get the logic but works
class Solution {
 public:
  void sortColors(vector<int> &nums) {
    int n = nums.size();
    // Next two lines are important
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
      if (nums[mid] == 0) {
        swap(nums[low], nums[mid]);
        low++;
        mid++;
      } else if (nums[mid] == 1)
        mid++;
      else {
        swap(nums[mid], nums[high]);
        high--;
      }
    }
  }
};