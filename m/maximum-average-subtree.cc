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
  map<TreeNode*, double> sum, siz;

  void dfs(TreeNode* root) {
    if (!root) return;
    dfs(root->left); dfs(root->right);
    siz[root] = siz[root->left] + siz[root->right] + 1;
    sum[root] = sum[root->left] + sum[root->right] + root->val;
  }

public:
  double maximumAverageSubtree(TreeNode* root) {
    dfs(root);
    double ans = 0;
    for (auto& [k, v] : sum) {
      ans = max(ans, v / siz[k]);
    }
    return ans;
  }
};
