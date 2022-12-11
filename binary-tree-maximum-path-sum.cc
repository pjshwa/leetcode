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
  int ans = -0x3f3f3f3f;

  int dfs1(TreeNode* v) {
    if (d.count(v)) return d[v];

    int ret = v->val;
    if (v->left) {
      ret = max(ret, dfs1(v->left) + v->val);
    }
    if (v->right) {
      ret = max(ret, dfs1(v->right) + v->val);
    }
    return d[v] = ret;
  }

  void dfs2(TreeNode* v) {
    int chsum = 0;
    if (v->left) {
      if (d[v->left] > 0) chsum += d[v->left];
      dfs2(v->left);
    }
    if (v->right) {
      if (d[v->right] > 0) chsum += d[v->right];
      dfs2(v->right);
    }
    ans = max(ans, v->val + chsum);
  }

public:
  int maxPathSum(TreeNode* root) {
    dfs1(root);
    dfs2(root);
    return ans;
  }
};
