#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
 public:
  Node *addOne(Node *head) {
    // reversing the linked list
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    Node *tr = prev;
    long long int carry = 1;
    while (tr != NULL) {
      if (tr->data == 9 && carry == 1) {
        tr->data = 0;
        carry = 1;
        if (tr->next == NULL) break;
        tr = tr->next;
      } else {
        tr->data = (tr->data) + carry;
        carry = 0;
        if (tr->next == NULL) break;
        tr = tr->next;
      }
    }
    if (carry == 1 && tr->data == 0) {
      Node *temp = new Node(1);
      temp->next = NULL;
      tr->next = temp;
      tr = temp;
    }

    Node *curr1 = prev;
    Node *prev1 = NULL;
    Node *next1 = NULL;
    while (curr1 != NULL) {
      next1 = curr1->next;
      curr1->next = prev1;
      prev1 = curr1;
      curr1 = next1;
    }
    return prev1;
  }
};