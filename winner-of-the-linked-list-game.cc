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
  string gameResult(ListNode* head) {
    int oc = 0, ec = 0;
    auto node = head;
    while (node) {
      int eval = node->val;
      node = node->next;
      int oval = node->val;
      node = node->next;

      if (oval > eval) ++oc;
      if (oval < eval) ++ec;
    }

    if (oc > ec) return "Odd";
    else if (oc < ec) return "Even";
    else return "Tie";
  }
};
