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
  map<TreeNode*, int> d;

  void dfs(TreeNode* node) {
    if (node == nullptr) return;
    dfs(node->left);
    dfs(node->right);
    d[node] = node->val;
    if (node->left) d[node] += d[node->left];
    if (node->right) d[node] += d[node->right];
  }

public:
  int equalToDescendants(TreeNode* root) {
    dfs(root);
    int ans = 0;
    for (auto [node, sum] : d) {
      if (sum == 2 * node->val) ans++;
    }
    return ans;
  }
};
