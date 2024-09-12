#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Question: Separate even place and odd place differently
class Solution {
 public:
  ListNode *oddEvenList(ListNode *head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode *first = head;
    ListNode *second = head->next;
    ListNode *attach = second;

    while (second != NULL && second->next != NULL) {
      first->next = first->next->next;
      second->next = second->next->next;
      first = first->next;
      second = second->next;
    }
    first->next = attach;
    return head;
  }
};
// TC: O(N)
// SC: O(1)

// Question: separate even numbers and odd numbers differently
ListNode *SegregatetoOddEVen(ListNode *head) {
  ListNode *oddHead = new ListNode(-1), *oddTail = oddHead;
  ListNode *evenHead = new ListNode(-1), *evenTail = evenHead;
  ListNode *curr = head, *temp;
  while (curr) {
    temp = curr;
    curr = curr->next;
    temp->next = nullptr;

    if (temp->val & 1) {
      oddTail->next = temp;
      oddTail = temp;
    } else {
      evenTail->next = temp;
      evenTail = temp;
    }
  }
  evenTail->next = oddHead->next;
  return evenHead->next;
}