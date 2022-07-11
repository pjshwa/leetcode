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
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return head;

    ListNode *cur = head, *tail;
    int n = 0;
    while (cur) {
      n++;
      tail = cur;
      cur = cur->next;
    }
    k = (n - (k % n)) % n;

    while (k--) {
      tail->next = head;
      head = head->next;
      tail = tail->next;
      tail->next = nullptr;
    }

    return head;
  }
};
