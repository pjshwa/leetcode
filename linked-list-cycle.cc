/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr) return false;

    ListNode *slow = head, *fast = head;
    do {
      if (fast == nullptr || fast->next == nullptr) return false;

      slow = slow->next;
      fast = fast->next->next;
    } while (slow != fast);

    return true;
  }
};
