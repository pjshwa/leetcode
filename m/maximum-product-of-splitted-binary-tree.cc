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
const int MOD = 1e9 + 7;

class Solution {
  map<TreeNode*, ll> vsz;
  ll tot, ans = 0;

  void dfs1(TreeNode* v) {
    vsz[v] = v->val;
    if (v->left) {
      dfs1(v->left);
      vsz[v] += vsz[v->left];
    }
    if (v->right) {
      dfs1(v->right);
      vsz[v] += vsz[v->right];
    }
  }

  void dfs2(TreeNode* v) {
    if (v->left) {
      ll val = vsz[v->left];
      ans = max(ans, val * (tot - val));
      dfs2(v->left);
    }
    if (v->right) {
      ll val = vsz[v->right];
      ans = max(ans, val * (tot - val));
      dfs2(v->right);
    }
  }

public:
  int maxProduct(TreeNode* root) {
    dfs1(root);
    tot = vsz[root];
    dfs2(root);
    return ans % MOD;
  }
};
