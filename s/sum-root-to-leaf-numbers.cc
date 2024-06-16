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
  int ans;
  void dfs(TreeNode* node, int acc) {
    int nacc = acc * 10 + node->val;
    if (node->left && node->right) {
      dfs(node->left, nacc);
      dfs(node->right, nacc);
    }
    else if (node->left) dfs(node->left, nacc);
    else if (node->right) dfs(node->right, nacc);
    else ans += nacc;
  }

public:
  int sumNumbers(TreeNode* root) {
    if (root) dfs(root, 0);
    return ans;
  }
};
