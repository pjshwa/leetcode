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
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;
    ListNode *cur = head;
    set<int> mark;

    bool flag = false;
    while (cur->next) {
      if (cur->val == cur->next->val) {
        mark.insert(cur->val);
        cur->next = cur->next->next;
      }
      else cur = cur->next;
    }

    while (head && mark.count(head->val)) head = head->next;
    cur = head;
    while (cur && cur->next) {
      if (mark.count(cur->next->val)) cur->next = cur->next->next;
      else cur = cur->next;
    }

    return head;
  }
};
