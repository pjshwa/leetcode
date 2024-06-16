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
  map<TreeNode*, int> node_sum, node_cnt;

  void dfs(TreeNode* node) {
    node_sum[node] = node->val;
    node_cnt[node] = 1;

    if (node->left) {
      dfs(node->left);
      node_sum[node] += node_sum[node->left];
      node_cnt[node] += node_cnt[node->left];
    }
    if (node->right) {
      dfs(node->right);
      node_sum[node] += node_sum[node->right];
      node_cnt[node] += node_cnt[node->right];
    }
  }

public:
  int averageOfSubtree(TreeNode* root) {
    if (root) dfs(root);
    int ans = 0;
    for (auto [node, sum] : node_sum) {
      ans += (sum / node_cnt[node] == node->val);
    }
    return ans;
  }
};
