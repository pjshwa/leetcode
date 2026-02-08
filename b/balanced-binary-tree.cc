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
  bool ok = true;
  int mDepth(TreeNode* node) {
    if (node == nullptr) return 0;
    int left_depth = mDepth(node->left);
    int right_depth = mDepth(node->right);
    if (abs(left_depth - right_depth) > 1) ok = false;
    return max(left_depth, right_depth) + 1;
  }

public:
  bool isBalanced(TreeNode* root) {
    mDepth(root);
    return ok;
  }
};
