#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Method 1: Better
class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode();
    ListNode *temp = head;
    int carry = 0;
    while (l1 != NULL && l2 != NULL) {
      int sum = 0;
      sum += carry;
      sum += (l1->val) + (l2->val);
      carry = sum / 10;

      ListNode *node = new ListNode(sum % 10);
      temp->next = node;
      temp = node;

      l1 = l1->next;
      l2 = l2->next;
    }
    while (l1 != NULL) {
      int sum = 0;
      sum += carry;
      sum += (l1->val);
      carry = sum / 10;

      ListNode *node = new ListNode(sum % 10);
      temp->next = node;
      temp = node;

      l1 = l1->next;
    }
    while (l2 != NULL) {
      int sum = 0;
      sum += carry;
      sum += (l2->val);
      carry = sum / 10;

      ListNode *node = new ListNode(sum % 10);
      temp->next = node;
      temp = node;

      l2 = l2->next;
    }
    if (carry != 0) {
      ListNode *node = new ListNode(carry);
      temp->next = node;
      temp = node;
    }
    return head->next;
  }
};
// Method 2: Optimal
class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode();
    ListNode *temp = dummy;
    int carry = 0;
    while ((l1 != NULL || l2 != NULL) || carry) {
      int sum = 0;
      if (l1 != NULL) {
        sum += l1->val;
        l1 = l1->next;
      }

      if (l2 != NULL) {
        sum += l2->val;
        l2 = l2->next;
      }

      sum += carry;
      carry = sum / 10;
      ListNode *node = new ListNode(sum % 10);
      temp->next = node;
      temp = temp->next;
    }
    return dummy->next;
  }
};