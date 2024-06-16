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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto cur = head; int sz = 0;
    while (cur) cur = cur->next, ++sz;

    n = sz - n;
    if (n == 0) return head->next;

    cur = head;
    for (int it = 0; it < n - 1; ++it) cur = cur->next;
    cur->next = cur->next->next;
    return head;
  }
};
