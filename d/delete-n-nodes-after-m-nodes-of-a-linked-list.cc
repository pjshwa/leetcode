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
  ListNode* deleteNodes(ListNode* head, int m, int n) {
    ListNode *cur = head, *prev = nullptr;
    while (1) {
      for (int i = 0; i < m && cur; ++i) {
        prev = cur;
        cur = cur->next;
      }
      if (!cur) break;
      for (int i = 0; i < n && cur; ++i) {
        prev->next = cur->next;
        cur = cur->next;
      }
      if (!cur) break;
    }
    return head;
  }
};
