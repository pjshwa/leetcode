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
  ListNode* doubleIt(ListNode* head) {
    vector<int> digits;
    auto cur = head;
    while (cur) {
      digits.push_back(cur->val);
      cur = cur->next;
    }
    reverse(digits.begin(), digits.end());

    int carry = 0;
    for (auto& d : digits) {
      d = d * 2 + carry;
      carry = d / 10;
      d %= 10;
    }
    if (carry) digits.push_back(carry);
    if (digits.empty()) digits.push_back(0);

    ListNode *newHead = nullptr, *prev = nullptr;
    while (!digits.empty()) {
      auto node = new ListNode(digits.back());
      digits.pop_back();
      if (!newHead) {
        newHead = node;
      } else {
        prev->next = node;
      }
      prev = node;
    }
    return newHead;
  }
};
