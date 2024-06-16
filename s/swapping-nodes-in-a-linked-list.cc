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
  ListNode* swapNodes(ListNode* head, int k) {
    int n = 0;
    ListNode *p = head;
    while (p) {
      n++;
      p = p->next;
    }
    ListNode *l1, *l2;
    p = head;
    for (int i = 1; i <= n; i++) {
      if (i == k) l1 = p;
      if (i == n - k + 1) l2 = p;
      p = p->next;
    }
    swap(l1->val, l2->val);
    return head;
  }
};
