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
  ListNode* reverseList(ListNode* head) {
    if (!head) return nullptr;

    auto cur = head;
    stack<int> s;
    while (cur) {
      s.push(cur->val);
      cur = cur->next;
    }

    auto ret = new ListNode(s.top()); s.pop(); cur = ret;
    while (!s.empty()) {
      auto node = new ListNode(s.top()); s.pop();
      cur->next = node;
      cur = node;
    }
    return ret;
  }
};
