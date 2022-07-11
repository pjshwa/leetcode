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
  void dfs(TreeNode* node, int val) {
    if (node->val < val) {
      if (node->right) dfs(node->right, val);
      else {
        node->right = new TreeNode(val);
        return;
      }
    }
    else {
      if (node->left) dfs(node->left, val);
      else {
        node->left = new TreeNode(val);
        return;
      }
    }
  }
public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);
    dfs(root, val);
    return root;
  }
};
