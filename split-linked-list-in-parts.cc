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
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int N = 0;
    ListNode* cur = head;
    while (cur) cur = cur->next, ++N;

    int cnts[k]; fill(cnts, cnts + k, N / k);
    for (int i = 0; i < N % k; ++i) ++cnts[i];

    vector<ListNode*> ret; cur = head;
    for (int chunk = 0; chunk < k; ++chunk) {
      if (cnts[chunk] == 0) {
        ret.push_back(nullptr);
        continue;
      }

      ListNode *chunk_head = new ListNode(cur->val);
      ListNode *chunk_cursor = chunk_head;
      cur = cur->next;

      for (int it = 1; it < cnts[chunk]; ++it) {
        chunk_cursor->next = new ListNode(cur->val);
        chunk_cursor = chunk_cursor->next;
        cur = cur->next;
      }

      ret.push_back(chunk_head);
    }
    return ret;
  }
};
