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

using ll = long long;
const ll MOD = 1e12;

class Solution {
  vector<ll> w[3001];

  void dfs(TreeNode* node, int d, ll v) {
    if (!node) return;
    w[d].push_back(v);
    if (node->left) dfs(node->left, d + 1, (2 * v) % MOD);
    if (node->right) dfs(node->right, d + 1, (2 * v + 1) % MOD);
  }
public:
  int widthOfBinaryTree(TreeNode* root) {
    dfs(root, 0, 1);

    ll ans = 0;
    for (int i = 0; i <= 3000; i++) {
      if (w[i].empty()) continue;
      ans = max(ans, (MOD + w[i].back() - w[i].front() + 1) % MOD);
    }
    return ans;
  }
};
