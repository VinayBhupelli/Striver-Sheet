#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node* next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
// Method 1:
Node* segregate(Node* head) {
  // Add code here
  multiset<int> m;
  Node* temp = head;

  while (temp != NULL) {
    m.insert(temp->data);
    temp = temp->next;
  }
  Node* last = head;

  for (auto& x : m) {
    last->data = x;
    last = last->next;
  }
  return head;
}

// Method 2:
class Solution {
 public:
  // Function to sort a linked list of 0s, 1s and 2s.
  Node* segregate(Node* head) {
    if (!head || !head->next) return head;

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    while (head) {
      if (head->data == 0) {
        zeroTail->next = head;
        zeroTail = zeroTail->next;
      } else if (head->data == 1) {
        oneTail->next = head;
        oneTail = oneTail->next;
      } else if (head->data == 2) {
        twoTail->next = head;
        twoTail = twoTail->next;
      }

      head = head->next;
    }
    // Important
    // check if ones exist
    if (oneHead->next) {
      zeroTail->next = oneHead->next;
      // directly link with start of twos
      oneTail->next = twoHead->next;
    } else {
      zeroTail->next = twoHead->next;
    }

    twoTail->next = NULL;

    return zeroHead->next;
  }
};