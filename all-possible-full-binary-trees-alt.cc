class Solution {
  map<int, vector<TreeNode*>> dp;

public:
  vector<TreeNode*> allPossibleFBT(int n) {
    if (n % 2 == 0) return {};
    if (n == 1) return {new TreeNode(0)};
    if (dp.count(n)) return dp[n];

    vector<TreeNode*> ret;
    for (int l = 1; l < n; l += 2) {
      auto left = allPossibleFBT(l);
      auto right = allPossibleFBT(n - 1 - l);
      for (auto ln : left) for (auto rn : right) {
        TreeNode* root = new TreeNode(0);
        root->left = ln;
        root->right = rn;
        ret.push_back(root);
      }
    }
    return dp[n] = ret;
  }
};
