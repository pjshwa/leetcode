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
  ListNode* partition(ListNode* head, int x) {
    ListNode* high = nullptr;
    ListNode* low = nullptr;

    ListNode* cur = head;
    ListNode* lhead = nullptr;
    ListNode* hhead = nullptr;
    while (cur) {
      int val = cur->val;
      if (val < x) {
        if (low) {
          low->next = new ListNode(val);
          low = low->next;
        }
        else low = lhead = new ListNode(val);
      }
      else {
        if (high) {
          high->next = new ListNode(val);
          high = high->next;
        }
        else high = hhead = new ListNode(val);
      }
      cur = cur->next;
    }

    if (low) {
      low->next = hhead;
      return lhead;
    }
    else return hhead;
  }
};
