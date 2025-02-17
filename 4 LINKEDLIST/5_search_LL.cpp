#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
 public:
  // Function to count nodes of a linked list.
  bool searchKey(int n, struct Node *head, int key) {
    Node *temp = head;
    while (temp != NULL) {
      if (temp->data == key) return true;
      temp = temp->next;
    }
    return false;
  }
};
// TC: O(N) worst case O(1) Best Case
// SC: O(1)