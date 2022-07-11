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
  int ans, mdepth;

  int dfs1(TreeNode* root) {
    if (!root) return 0;
    int res = 0;
    if (root->left) res = max(res, dfs1(root->left));
    if (root->right) res = max(res, dfs1(root->right));
    return res + 1;
  }

  void dfs2(TreeNode* root, int depth) {
    if (!root) return;
    if (root->left) dfs2(root->left, depth + 1);
    if (root->right) dfs2(root->right, depth + 1);

    if (depth == mdepth) ans += root->val;
  }
public:
  int deepestLeavesSum(TreeNode* root) {
    mdepth = dfs1(root);
    ans = 0;
    dfs2(root, 1);
    return ans;
  }
};
