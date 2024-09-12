#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x) {
    data = x;
    next = NULL;
    prev = NULL;
  }
};

// Delete xth position element in DLL
// Logic: keep count and position at the same node
class Solution {
 public:
  //  (position starts from 1)
  Node *deleteNode(Node *head, int x) {
    if (head == NULL) return NULL;
    if (x == 1) return head->next;
    Node *temp = head;
    int count = 1;
    // instead keep condition as count<x
    while (temp->next != NULL) {
      if (count == x) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
      }
      temp = temp->next;
      count++;
    }
    if (count == x) temp->prev->next = temp->next;
    return head;
  }
};
// TC:O(pos)
// SC:O(1)

// Delete Head
Node *deleteHead(Node *head) {
  if (head == nullptr || head->next == nullptr) {
    return nullptr;
  }
  Node *prev = head;
  head = head->next;
  head->prev = nullptr;
  prev->next = nullptr;

  delete prev;

  return head;
}
// TC:O(1)
// SC:O(1)

// Delete Tail
Node *deleteTail(Node *head) {
  if (head == nullptr || head->next == nullptr) return nullptr;

  Node *tail = head;
  while (tail->next != nullptr) {
    tail = tail->next;
  }

  Node *newTail = tail->prev;
  newTail->next = nullptr;
  tail->prev = nullptr;

  // Free memory of the deleted node
  delete tail;

  return head;
}
// TC:O(N)
// SC:O(1)