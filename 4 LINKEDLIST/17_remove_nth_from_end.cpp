#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// Method 1:
ListNode* DeleteNthNodefromEnd(ListNode* head, int N) {
  if (head == NULL) {
    return NULL;
  }
  // Find the length of the linked list
  int cnt = 0;
  ListNode* temp = head;
  while (temp != NULL) {
    cnt++;
    temp = temp->next;
  }
  // check whether N is equal to cnt
  if (cnt == N) {
    ListNode* newhead = head->next;
    delete (head);
    return newhead;
  }
  // traverse the remaining len
  int res = cnt - N;
  temp = head;
  while (--res) {
    temp = temp->next;
  }
  ListNode* delNode = temp->next;
  temp->next = temp->next->next;
  delete (delNode);
  return head;
}
// Method 2:
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fast = head, *slow = head;
    for (int i = 0; i < n; i++) fast = fast->next;
    // If the deleting element is head
    if (!fast) return head->next;
    // if while traversing fast reaches null then
    // we will be at the node to be deleted
    while (fast->next) fast = fast->next, slow = slow->next;
    slow->next = slow->next->next;
    return head;
  }
};