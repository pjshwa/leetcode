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
  int depth = 0;
  void dfs(TreeNode* node, int depth) {
    this->depth = max(this->depth, depth);
    if (node->left) dfs(node->left, depth + 1);
    if (node->right) dfs(node->right, depth + 1);
  }
public:
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    dfs(root, 1);
    return depth;
  }
};
