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
  int tilt = 0;
  int dfs(TreeNode* root) {
    int left = 0, right = 0;
    if (root->left) left = dfs(root->left);
    if (root->right) right = dfs(root->right);
    tilt += abs(left - right);
    return root->val + left + right;
  }

public:
  int findTilt(TreeNode* root) {
    if (root) dfs(root);
    return tilt;
  }
};
