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
  vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    vector<int> nodes;
    auto cur = head;
    while (cur) {
      nodes.push_back(cur->val);
      cur = cur->next;
    }

    vector<int> cpi; int N = nodes.size();
    for (int i = 1; i < N - 1; ++i) {
      if (nodes[i] > nodes[i - 1] && nodes[i] > nodes[i + 1]) {
        cpi.push_back(i);
      }
      else if (nodes[i] < nodes[i - 1] && nodes[i] < nodes[i + 1]) {
        cpi.push_back(i);
      }
    }
    if (cpi.size() < 2) return {-1, -1};

    int mind = INT_MAX, maxd = cpi.back() - cpi[0];
    for (int i = 1; i < cpi.size(); ++i) {
      mind = min(mind, cpi[i] - cpi[i - 1]);
    }
    return {mind, maxd};
  }
};
