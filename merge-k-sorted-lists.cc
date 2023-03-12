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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    struct Compare {
      bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
      }
    };
    priority_queue<ListNode*, vector<ListNode*>, Compare> wait;
    for (auto& p : lists) if (p) wait.push(p);

    ListNode *ret = nullptr, *cur = nullptr;
    while (!wait.empty()) {
      ListNode* top = wait.top(); wait.pop();

      if (ret == nullptr) {
        ret = top;
        cur = ret;
      }
      else {
        cur->next = top;
        cur = cur->next;
      }

      if (top->next) wait.push(top->next);
    }

    return ret;
  }
};
