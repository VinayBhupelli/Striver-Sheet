#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  Node *prev;
  int data;
  Node *next;

  Node() {
    prev = NULL;
    data = 0;
    next = NULL;
  }

  Node(int value) {
    prev = NULL;
    data = value;
    next = NULL;
  }
};
class Solution {
 public:
  Node *constructDLL(vector<int> &arr) {
    Node *head = new Node(arr[0]);
    Node *temp = head;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
      Node *newNode = new Node(arr[i]);
      temp->next = newNode;
      newNode->prev = temp;
      temp = newNode;
    }
    return head;
  }
};
// TC:O(N)
// SC:O(1)