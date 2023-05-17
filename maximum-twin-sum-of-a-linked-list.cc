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
  int pairSum(ListNode* head) {
    int N = 0; ListNode* p = head;
    while (p) { N++; p = p->next; }

    vector<int> A(N / 2); p = head;
    for (int i = 0; i < N / 2; i++) {
      A[i] += p->val; p = p->next;
    }
    for (int i = N / 2; i < N; i++) {
      A[N - i - 1] += p->val; p = p->next;
    }
    return *max_element(A.begin(), A.end());
  }
};
