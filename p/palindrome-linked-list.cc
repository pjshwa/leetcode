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
  bool isPalindrome(ListNode* head) {
    ListNode* cur = head;
    int len = 0;
    while (cur) {
      len++;
      cur = cur->next;
    }

    cur = head;
    int clen = 0;
    stack<int> pre;
    bool of = len & 1;
    while (cur) {
      clen++;
      if (clen <= len / 2) pre.push(cur->val);
      else {
        if (of) of = 0;
        else if (cur->val != pre.top()) return false;
        else pre.pop();
      }
      cur = cur->next;
    }
    return true;
  }
};
