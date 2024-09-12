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
ListNode* rotateRight(ListNode* head, int k) {
  if (head == NULL || head->next == NULL) return head;
  for (int i = 0; i < k; i++) {
    ListNode* temp = head;
    while (temp->next->next != NULL) temp = temp->next;

    ListNode* end = temp->next;
    temp->next = NULL;
    end->next = head;
    head = end;
  }
  return head;
}

// Method 2:
class Solution {
 public:
  ListNode* findNthNode(ListNode* head, int N) {
    while (--N) head = head->next;
    return head;
  }
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL) return NULL;
    ListNode* temp = head;
    int len = 1;
    // first find the length
    while (temp->next != NULL) {
      temp = temp->next;
      len++;
    }
    if (k % len == 0) return head;
    k = k % len;
    temp->next = head;
    ListNode* NthNode = findNthNode(head, len - k);
    head = NthNode->next;
    NthNode->next = NULL;
    return head;
  }
};