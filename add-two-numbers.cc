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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *res = new ListNode(0), *cur = res;

    bool carry = false;
    while (l1 && l2) {
      int val = l1->val + l2->val;
      if (carry) {
        val += 1;
        carry = false;
      }
      if (val >= 10) {
        val -= 10;
        carry = true;
      }
      cur->next = new ListNode(val);
      cur = cur->next;
      l1 = l1->next;
      l2 = l2->next;
    }

    while (l1) {
      int val = l1->val;
      if (carry) {
        val += 1;
        carry = false;
      }
      if (val >= 10) {
        val -= 10;
        carry = true;
      }
      cur->next = new ListNode(val);
      cur = cur->next;
      l1 = l1->next;
    }

    while (l2) {
      int val = l2->val;
      if (carry) {
        val += 1;
        carry = false;
      }
      if (val >= 10) {
        val -= 10;
        carry = true;
      }
      cur->next = new ListNode(val);
      cur = cur->next;
      l2 = l2->next;
    }

    if (carry) cur->next = new ListNode(1);

    return res->next;
  }
};
