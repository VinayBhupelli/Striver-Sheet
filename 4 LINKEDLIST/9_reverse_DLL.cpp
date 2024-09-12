#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node *prev;
  Node(int x) {
    data = x;
    next = NULL;
    prev = NULL;
  }
};
// Method 1:
// Pushing elements into the stack
Node *reverseDLL(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  stack<int> st;
  Node *temp = head;
  while (temp != NULL) {
    st.push(temp->data);
    temp = temp->next;
  }
  temp = head;
  while (temp != NULL) {
    temp->data = st.top();
    st.pop();
    temp = temp->next;
  }
  return head;
}
// TC: O(2N)
// SC: O(N)

// Method 2: Three Pointers
class Solution {
 public:
  Node *reverseDLL(Node *head) {
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = head;
    while (curr != NULL) {
      next = curr->next;
      //   just rotate the pointers
      curr->next = prev;
      curr->prev = next;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};

// Method 3: Two Pointers
class Solution {
 public:
  Node *reverseDLL(Node *head) {
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL) {
      prev = curr->prev;
      curr->prev = curr->next;
      curr->next = prev;

      curr = curr->prev;
    }
    return prev;
  }
};