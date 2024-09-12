#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Method 1:
ListNode *reverseLinkedList(ListNode *head) {
  ListNode *temp = head;
  stack<int> st;
  while (temp != nullptr) {
    st.push(temp->val);
    temp = temp->next;
  }
  temp = head;
  while (temp != nullptr) {
    temp->val = st.top();
    st.pop();
    temp = temp->next;
  }
  return head;
}
// Method 2: 3 Pointers
class Solution {
 public:
  ListNode *reverseList(ListNode *head) {
    ListNode *curr = head;
    ListNode *next = NULL;
    ListNode *prev = NULL;
    while (curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};
// Method 3: Recursive
ListNode *reverseLinkedList(ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  ListNode *newHead = reverseLinkedList(head->next);
  head->next->next = head;
  head->next = NULL;
  return newHead;
}