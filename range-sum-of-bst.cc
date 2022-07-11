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
  int ans = 0, low, high;

  void dfs(TreeNode* node) {
    if (low <= node->val && node->val <= high) ans += node->val;
    if (node->left) dfs(node->left);
    if (node->right) dfs(node->right);
  }

public:
  int rangeSumBST(TreeNode* root, int low, int high) {
    this->low = low;
    this->high = high;
    if (root) dfs(root);
    return ans;
  }
};
