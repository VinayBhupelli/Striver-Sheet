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
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *temp;
    while (headA != NULL) {
      temp = headB;
      while (temp != NULL) {
        if (headA == temp) {
          return headA;
        }
        temp = temp->next;
      }
      headA = headA->next;
    }
    return NULL;
  }
};
// Method 2:
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode *, int> m;
    while (headA != NULL) {
      m[headA]++;
      headA = headA->next;
    }
    while (headB != NULL) {
      if (m[headB] > 0) {
        return headB;
      }
      headB = headB->next;
    }
    return NULL;
  }
};
// Method 3:
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int len1 = 1, len2 = 1;
    ListNode *temp1 = headA;
    ListNode *temp2 = headB;
    ListNode *pointer1 = headA;
    ListNode *pointer2 = headB;

    while (temp1->next != NULL) {
      temp1 = temp1->next;
      len1++;
    }
    while (temp2->next != NULL) {
      temp2 = temp2->next;
      len2++;
    }
    if (temp1 != temp2) return NULL;
    if (len1 >= len2) {
      int diff = len1 - len2;
      while (diff--) {
        pointer1 = pointer1->next;
      }
    } else if (len1 < len2) {
      int diff = len2 - len1;
      while (diff--) {
        pointer2 = pointer2->next;
      }
    }
    while (pointer1 != pointer2) {
      pointer1 = pointer1->next;
      pointer2 = pointer2->next;
    }
    return pointer1;
  }
};

// optimal Method 4:
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA, *b = headB;
    while (a != b) {
      a = !a ? headB : a->next;
      b = !b ? headA : b->next;
    }
    return a;
  }
};