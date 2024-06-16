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
  ListNode* frequenciesOfElements(ListNode* head) {
    map<int, int> tal;

    auto cur = head;
    while (cur) {
      ++tal[cur->val];
      cur = cur->next;
    }

    ListNode* freq_head = nullptr;
    cur = new ListNode(0);
    for (auto& [_, v] : tal) {
      cur->next = new ListNode(v);
      if (freq_head == nullptr) freq_head = cur->next;
      cur = cur->next;
    }
    return freq_head;
  }
};
