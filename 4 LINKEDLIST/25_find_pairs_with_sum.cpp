#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
  Node(int x) {
    data = x;
    next = NULL;
    prev = NULL;
  }
};
// Method 1: TLE
vector<pair<int, int>> findPairsWithGivenSum(Node* head, int target) {
  vector<pair<int, int>> res;
  Node* temp1 = head;
  while (temp1 != NULL) {
    Node* temp2 = temp1->next;
    while (temp2 != NULL) {
      if (temp1->data + temp2->data == target)
        res.push_back({temp1->data, temp2->data});
      temp2 = temp2->next;
    }
    temp1 = temp1->next;
  }
  return res;
}
// Method 2:
Node* findTail(Node* head) {
  while (head->next != NULL) head = head->next;
  return head;
}
vector<pair<int, int>> findPairsWithGivenSum(Node* head, int target) {
  vector<pair<int, int>> res;
  Node *left = head, *right = findTail(head);
  while (left->data < right->data) {
    if (left->data + right->data == target) {
      res.push_back({left->data, right->data});
      left = left->next;
      right = right->prev;
    } else if (left->data + right->data < target)
      left = left->next;
    else
      right = right->prev;
  }
  return res;
}