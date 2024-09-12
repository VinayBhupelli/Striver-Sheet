#include <bits/stdc++.h>
using namespace std;
// Method 1: Separate pos & neg and page alternative by traversing n/2 through
// these elements
vector<int> RearrangebySign(vector<int> A, int n) {
  vector<int> pos;
  vector<int> neg;
  for (int i = 0; i < n; i++) {
    if (A[i] > 0)
      pos.push_back(A[i]);
    else
      neg.push_back(A[i]);
  }
  for (int i = 0; i < n / 2; i++) {
    A[2 * i] = pos[i];
    A[2 * i + 1] = neg[i];
  }
  return A;
}
// Method 2: use two pointer
class Solution {
 public:
  vector<int> rearrangeArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n);
    int i = 0, j = 1;
    for (int k = 0; k < n; k++) {
      if (nums[k] > 0) {
        res[i] = nums[k];
        i += 2;
      } else {
        res[j] = nums[k];
        j += 2;
      }
    }
    return res;
  }
};