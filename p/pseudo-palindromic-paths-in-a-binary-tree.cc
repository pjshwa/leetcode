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

  void dfs(TreeNode* v, int lev, int state) {
    if (v->left || v->right) {
      if (v->left) dfs(v->left, lev + 1, state ^ (1 << (v->left->val)));
      if (v->right) dfs(v->right, lev + 1, state ^ (1 << (v->right->val)));
    }
    else {
      int cnt = __builtin_popcount(state);
      if (lev & 1) {
        if (cnt == 1) ans++;
      }
      else {
        if (cnt == 0) ans++;
      }
    }
  }

public:
  int pseudoPalindromicPaths (TreeNode* root) {
    ans = 0;
    dfs(root, 1, 1 << (root->val));
    return ans;
  }
};
