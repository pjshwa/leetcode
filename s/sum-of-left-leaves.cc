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
public:
  int sumOfLeftLeaves(TreeNode* root) {
    return helper(root, -1);
  }

  int helper(TreeNode* node, int dir) {
    bool is_leaf = (node->left == nullptr && node->right == nullptr);
    if (is_leaf) return node->val * (dir == 0);

    int sum = 0;
    if (node->left != nullptr) {
      sum += helper(node->left, 0);
    }
    if (node->right != nullptr) {
      sum += helper(node->right, 1);
    }
    return sum;
  }
};
