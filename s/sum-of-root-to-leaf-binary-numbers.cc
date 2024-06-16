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
  void dfs(TreeNode* node, int cur) {
    int nval = cur + node->val;
    if (node->left == nullptr && node->right == nullptr) {
      ans += nval;
      return;
    }
    if (node->left != nullptr) dfs(node->left, nval * 2);
    if (node->right != nullptr) dfs(node->right, nval * 2);
  }
public:
  int sumRootToLeaf(TreeNode* root) {
    if (!root) return 0;
    ans = 0;
    dfs(root, 0);
    return ans;
  }
};
