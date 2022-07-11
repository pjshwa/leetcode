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
  int getDecimalValue(ListNode* head) {
    ListNode* p = head;
    stack<int> s;
    while (p) {
      s.push(p->val);
      p = p->next;
    }

    int ans = 0, pw = 1;
    while (!s.empty()) {
      ans += s.top() * pw;
      s.pop();
      pw *= 2;
    }
    return ans;
  }
};
