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
void findMiddle(ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return;
  }

  ListNode *temp = head;
  int count = 0;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  int mid = count / 2;
  temp = head;
  while (mid--) {
    if (mid == 0) {
      ListNode *middle = temp->next;
      temp->next = temp->next->next;
      delete middle;
      break;
    }
    temp = temp->next;
  }
}
// Method 2:
class Solution {
 public:
  ListNode *deleteMiddle(ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL;
    ListNode *slow = head;
    ListNode *fast = head;

    ListNode *prev;
    while (fast != NULL && fast->next != NULL) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = prev->next->next;
    return head;
  }
};
// Method 3:
class Solution {
 public:
  ListNode *deleteMiddle(ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL;

    ListNode *slow = head;
    ListNode *fast = head->next->next;

    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
  }
};