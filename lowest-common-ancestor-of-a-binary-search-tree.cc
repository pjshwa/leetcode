/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* cur = root;
    bool pl = cur->val < p->val, ql = cur->val < q->val;
    while (pl == ql) {
      if (cur == p) return p;
      if (cur == q) return q;

      if (pl && ql) cur = cur->right;
      else cur = cur->left;

      pl = cur->val < p->val, ql = cur->val < q->val;
    }
    return cur;
  }
};
