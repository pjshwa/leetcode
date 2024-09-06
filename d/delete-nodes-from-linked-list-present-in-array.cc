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
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    set<int> s(nums.begin(), nums.end());

    ListNode* dummy = new ListNode(0);
    auto cur = head; auto dummy_head = dummy;
    while (cur) {
      if (s.find(cur->val) == s.end()) {
        dummy->next = cur;
        dummy = dummy->next;
      }
      cur = cur->next;
    }
    dummy->next = nullptr;
    return dummy_head->next;
  }
};
