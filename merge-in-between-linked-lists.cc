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
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

    int it = 0;
    ListNode *cur = list1, *resume = list1;
    while (cur) {
      auto ncur = cur->next;
      if (it == a - 1) cur->next = list2;
      if (it == b) resume = cur->next;
      cur = ncur;
      it++;
    }

    cur = list2;
    while (cur->next) cur = cur->next;
    cur->next = resume;

    return list1;
  }
};
