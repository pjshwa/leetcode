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
  ListNode* deleteDuplicatesUnsorted(ListNode* head) {
    map<int, int> tal;
    for (auto p = head; p; p = p->next) ++tal[p->val];

    while (head && tal[head->val] > 1) head = head->next;
    for (auto p = head; p;) {
      while (p->next && tal[p->next->val] > 1) p->next = p->next->next;
      p = p->next;
    }
    return head;
  }
};
