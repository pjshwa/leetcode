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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  vector<int> A;

  TreeNode* construct(int l, int r) {
    if (l > r) return nullptr;
    if (l == r) return new TreeNode(A[l]);

    int m = (l + r) / 2;
    TreeNode* ret = new TreeNode(A[m]);
    ret->left = construct(l, m - 1);
    ret->right = construct(m + 1, r);
    return ret;
  }

public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;

    ListNode* cur = head;
    while (cur) A.push_back(cur->val), cur = cur->next;
    return construct(0, A.size() - 1);
  }
};
