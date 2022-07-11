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
  void reorderList(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode* mid = slow->next;
    slow->next = nullptr;

    // reverse list
    ListNode* cur = mid;
    ListNode* prev = nullptr;
    while (cur) {
      ListNode* next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    // merge
    ListNode* p = head;
    ListNode* q = prev;
    while (p && q) {
      ListNode* px = p->next;
      ListNode* qx = q->next;
      p->next = q;
      q->next = px;
      p = px;
      q = qx;
    }
  }
};
