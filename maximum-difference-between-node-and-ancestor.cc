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
  int ans = 0;
  void dfs(TreeNode* node, int mmin, int mmax) {
    ans = max(ans, mmax - mmin);
    if (node->left) {
      dfs(node->left, min(mmin, node->left->val), max(mmax, node->left->val));
    }
    if (node->right) {
      dfs(node->right, min(mmin, node->right->val), max(mmax, node->right->val));
    }
  }

public:
  int maxAncestorDiff(TreeNode* root) {
    int val = root->val;
    dfs(root, val, val);
    return ans;
  }
};
