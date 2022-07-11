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
  ListNode *head;
public:
  Solution(ListNode* head) {
    this->head = head;
  }
  
  int getRandom() {
    int res = head->val;
    ListNode *cur = head->next;
    int i = 2;
    while (cur) {
      int j = rand() % i;
      if (j == 0) res = cur->val;
      i++;
      cur = cur->next;
    }
    return res;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
 