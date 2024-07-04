/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* mergeNodes(ListNode* head) {
    auto cur = head;
    while (cur->next) {
      if (cur->val != 0 && cur->next->val != 0) {
        cur->val += cur->next->val;
        cur->next = cur->next->next;
      }
      else {
        cur = cur->next;
      }
    }

    cur = head->next;
    while (cur) {
      cur->next = cur->next->next;
      cur = cur->next;
    }
    return head->next;
  }
};
