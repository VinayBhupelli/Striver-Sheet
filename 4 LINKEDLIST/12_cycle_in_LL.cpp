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
bool detectLoop(ListNode *head) {
  ListNode *temp = head;
  unordered_map<ListNode *, int> nodeMap;
  while (temp != nullptr) {
    if (nodeMap.find(temp) != nodeMap.end()) {
      return true;
    }
    nodeMap[temp] = 1;
    temp = temp->next;
  }
  return false;
}
// TC: O(N*2*log(N))
// Even though unordered_map we are taking the avg case here,
// in best case O(1) in worst case O(N)
// so avg becomes O(logN)

// Method 2:
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        return true;
      }
    }
    return false;
  }
};

// The key insight here is the relative speed between these pointers. The fast
// pointer, moving at double the speed of the slow one, closes the gap between
// them by one node in every iteration. This means that with each step, the
// distance decreases by one node.

// start-fast = distance
// start'-fast' = (start+1)-(fast+2)
// start'-fast' = distance-1
// so eventually after distance moves they meet if they are in loop

// TC: O(N)
// The key insight into why this is O(N) and not something slower is that each
// step of the algorithm reduces the distance between the fast and slow pointers
// (when they are in the loop) by one. Therefore, the maximum number of steps
// needed for them to meet is proportional to the number of nodes in the list.