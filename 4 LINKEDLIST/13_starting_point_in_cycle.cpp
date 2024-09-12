#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL;

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *entry = head;

    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        while (slow != entry) {
          slow = slow->next;
          entry = entry->next;
        }
        return entry;
      }
    }
    return NULL;
  }
};
// L1 is defined as the distance between the head point and entry point
// L2 is defined as the distance between the entry point and the meeting point
// C is defined as the length of the cycle
// n is defined as the travel times of the fast pointer around the cycle When
// the first encounter of the slow pointer and the fast pointer

// According to the definition of L1, L2 and C, we can obtain:
// total distance of the slow pointer traveled when encounter is L1 + L2
// total distance of the fast pointer traveled when encounter is L1 + L2 + n * C

// Because the total distance the fast pointer traveled is twice as the slow
// pointer, Thus:

// 2*(L1+L2) = L1 + L2 + n * C => L1 + L2 = n * C => L1 = (n-1)C+(C-L2)*

// It can be concluded that the distance between the head location and entry
// location is equal to the distance between the meeting location and the entry
// location along the direction of forward movement.