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
  int dep = -1, val;

  void dfs(TreeNode* node, int d) {
    if (node == nullptr) return;
    if (d > dep) dep = d, val = node->val;
    dfs(node->left, d + 1);
    dfs(node->right, d + 1);
  }

public:
  int findBottomLeftValue(TreeNode* root) {
    dfs(root, 0);
    return val;
  }
};
