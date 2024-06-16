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
    stack<int> S1, S2, ans;

    ListNode* p = l1;
    while (p) S1.push(p->val), p = p->next;
    p = l2;
    while (p) S2.push(p->val), p = p->next;

    int carry = 0;
    while (!S1.empty() || !S2.empty()) {
      int v1 = 0, v2 = 0;
      if (!S1.empty()) v1 = S1.top(), S1.pop();
      if (!S2.empty()) v2 = S2.top(), S2.pop();

      int sum = v1 + v2 + carry;
      carry = sum / 10;
      ans.push(sum % 10);
    }
    if (carry) ans.push(carry);

    ListNode *ret, *l3 = nullptr;
    while (!ans.empty()) {
      int val = ans.top(); ans.pop();
      if (l3 == nullptr) {
        l3 = ret = new ListNode(val);
      }
      else {
        l3->next = new ListNode(val);
        l3 = l3->next;
      }
    }
    return ret;
  }
};
