map<pair<TreeNode*, bool>, int> dp;

class Solution {

  int dfs(TreeNode* node, bool s) {
    if (dp.count(make_pair(node, s))) return dp[make_pair(node, s)];

    int ans = s ? node->val : 0, lres = 0, rres = 0;
    if (node->left) {
      lres = dfs(node->left, false);
      if (!s) lres = max(lres, dfs(node->left, true));
    }
    if (node->right) {
      rres = dfs(node->right, false);
      if (!s) rres = max(rres, dfs(node->right, true));
    }
    return dp[make_pair(node, s)] = ans + lres + rres;
  }

public:
  int rob(TreeNode* root) {
    return max(dfs(root, true), dfs(root, false));
  }
};

