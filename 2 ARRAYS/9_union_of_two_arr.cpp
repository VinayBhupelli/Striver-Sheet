#include <bits/stdc++.h>
using namespace std;
// Method 1: Using Hashmap
vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {
  map<int, int> freq;
  vector<int> Union;
  for (int i = 0; i < n; i++) freq[arr1[i]]++;
  for (int i = 0; i < m; i++) freq[arr2[i]]++;
  for (auto &it : freq) Union.push_back(it.first);
  return Union;
}
// Method 2: using set
vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {
  set<int> s;
  vector<int> Union;
  for (int i = 0; i < n; i++) s.insert(arr1[i]);
  for (int i = 0; i < m; i++) s.insert(arr2[i]);
  for (auto &it : s) Union.push_back(it);
  return Union;
}
// Method 3: using two pointer
class Solution {
 public:
  vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
    vector<int> res;
    int i = 0, j = 0;
    while (i < n && j < m) {
      if (arr1[i] <= arr2[j]) {
        if (res.size() == 0 || res.back() != arr1[i]) res.push_back(arr1[i]);
        i++;
      } else {
        if (res.size() == 0 || res.back() != arr2[j]) res.push_back(arr2[j]);
        j++;
      }
    }
    while (i < n) {
      if (res.size() == 0 || res.back() != arr1[i]) res.push_back(arr1[i]);
      i++;
    }
    while (j < m) {
      if (res.size() == 0 || res.back() != arr2[j]) res.push_back(arr2[j]);
      j++;
    }
    return res;
  }
};