#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node* next;
  struct Node* bottom;
  Node(int x) {
    data = x;
    next = NULL;
    bottom = NULL;
  }
};
// BruteForce: store all the values and sort and make a new linkedlist
Node* flatten(Node* root) {
  // store all the elements
  vector<int> arr;
  Node* temp = root;
  while (temp != NULL) {
    Node* vert = temp;
    while (vert != NULL) {
      arr.push_back(vert->data);
      vert = vert->bottom;
    }
    temp = temp->next;
  }
  // Make sorting
  sort(arr.begin(), arr.end());
  // create a new linked list
  Node* dummy = new Node(-1);
  Node* res = dummy;
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    Node* temp = new Node(arr[i]);
    res->bottom = temp;
    res = temp;
  }
  return dummy->bottom;
}
// TC: O(NM) + O(NM logNM) + O(NM)
// traverse all elements + sorting + creating new linked list
// SC: O(N) array

// Method 2:
class Solution {
 public:
  Node* MergeLL(Node* list1, Node* list2) {
    Node* dummy = new Node(-1);
    Node* res = dummy;
    while (list1 != NULL && list2 != NULL) {
      if (list1->data < list2->data) {
        res->bottom = list1;
        res = list1;
        list1 = list1->bottom;
      } else {
        res->bottom = list2;
        res = list2;
        list2 = list2->bottom;
      }
    }
    if (list1 != NULL) res->bottom = list1;
    if (list2 != NULL) res->bottom = list2;
    return dummy->bottom;
  }
  Node* flatten(Node* root) {
    if (root == NULL || root->next == NULL) return root;
    Node* newNode = flatten(root->next);
    Node* res = MergeLL(root, newNode);
    return res;
  }
};
// TC: O(N * merge)
// TC: O(N * 2M)
// TC: O(2NM)
// SC: O(N) recurive stack space only