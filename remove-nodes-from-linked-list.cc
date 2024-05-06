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
  ListNode* removeNodes(ListNode* head) {
    vector<ListNode*> nodes;
    auto cur = head;
    while (cur) {
      while (!nodes.empty() && nodes.back()->val < cur->val) {
        nodes.pop_back();
      }
      nodes.push_back(cur);
      cur = cur->next;
    }

    int Z = nodes.size();
    for (int i = 0; i < Z; i++) {
      nodes[i]->next = i + 1 < Z ? nodes[i + 1] : nullptr;
    }
    return nodes[0];
  }
};
