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
  void dfs_mark(TreeNode* node, int target) {
    bool is_leaf = true;
    if (node->left) dfs_mark(node->left, target), is_leaf = false;
    if (node->right) dfs_mark(node->right, target), is_leaf = false;
    if (is_leaf && node->val == target) node->val = -1;
  }

  void dfs_conn(TreeNode* node, int target) {
    if (node->left) {
      dfs_conn(node->left, target);
      if (node->left->val == -1) node->left = nullptr;
    }
    if (node->right) {
      dfs_conn(node->right, target);
      if (node->right->val == -1) node->right = nullptr;
    }
    if (node->val == target && !node->left && !node->right) {
      node->val = -1;
    }
  }

public:
  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    dfs_mark(root, target);
    dfs_conn(root, target);
    return root->val == -1 ? nullptr : root;
  }
};
