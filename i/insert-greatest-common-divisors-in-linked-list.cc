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
  ListNode* insertGreatestCommonDivisors(ListNode* head) {
    auto cur = head;
    while (cur->next) {
      int v1 = cur->val, v2 = cur->next->val;
      int g = gcd(v1, v2);

      auto node = new ListNode(g, cur->next);
      cur->next = node;
      cur = node->next;
    }
    return head;
  }
};
