#include <bits/stdc++.h>
using namespace std;
// Sliding Window Concept doesn't work when array has 0 or negative elements.
// You can use Hashing(For Most Optimal Solution), store prefix sum in map and
// their index. Hope this helps!

// Method 1: n^3 loop
int getLongestSubarray(vector<int> &a, long long k) {
  int n = a.size();  // size of the array.

  int len = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      long long s = 0;
      for (int K = i; K <= j; K++) {
        s += a[K];
      }

      if (s == k) len = max(len, j - i + 1);
    }
  }
  return len;
}
// Method 2: n^2 loop
int getLongestSubarray(vector<int> &a, long long k) {
  int n = a.size();
  int len = 0;
  for (int i = 0; i < n; i++) {
    long long s = 0;
    for (int j = i; j < n; j++) {
      s += a[j];
      if (s == k) len = max(len, j - i + 1);
    }
  }
  return len;
}
// Method 3: hashing
// this works with negative numbers also
class Solution {
 public:
  int lenOfLongSubarr(int A[], int N, int K) {
    int len = 0;
    int sum = 0;
    unordered_map<int, int> hm;

    for (int i = 0; i < N; i++) {
      sum += A[i];
      if (sum == K) {
        len = max(len, i + 1);
      }
      // sum-K here not K-sum
      int rem = sum - K;
      if (hm.find(rem) != hm.end()) {
        int index = hm[rem];
        len = max(len, i - index);
      }
      if (hm.find(sum) == hm.end()) hm[sum] = i;
    }
    return len;
  }
};
// Method 4: Two Pointers
int getLongestSubarray(vector<int> &a, long long k) {
  int n = a.size();  // size of the array.

  int left = 0, right = 0;  // 2 pointers
  long long sum = a[0];
  int maxLen = 0;
  while (right < n) {
    // if sum > k, reduce the subarray from left
    // until sum becomes less or equal to k:
    while (left <= right && sum > k) {
      sum -= a[left];
      left++;
    }

    // if sum = k, update the maxLen i.e. answer:
    if (sum == k) {
      maxLen = max(maxLen, right - left + 1);
    }

    // Move forward thw right pointer:
    right++;
    if (right < n) sum += a[right];
  }

  return maxLen;
}
