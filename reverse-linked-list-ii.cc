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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    stack<ListNode*> s;

    int i = 1;
    ListNode* cur = head;
    ListNode* htail;
    ListNode* thead;

    while (i <= right) {
      if (i == left - 1) htail = cur;
      else if (i >= left) s.push(cur);
      cur = cur->next;
      i++;
    }
    thead = cur;

    if (left == 1) {
      head = htail = s.top();
      s.pop();
    }

    while (!s.empty()) {
      ListNode* t = s.top();
      s.pop();

      htail->next = t;
      htail = t;
    }
    htail->next = thead;
    return head;
  }
};
