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

const int INF = 0x3f3f3f3f;

class Solution {
  int ans;
  void dfs(TreeNode* v, int val) {
    if (v->val >= val) ans++;
    val = max(val, v->val);
    if (v->left) dfs(v->left, val);
    if (v->right) dfs(v->right, val);
  }

public:
  int goodNodes(TreeNode* root) {
    ans = 0;
    dfs(root, -INF);
    return ans;
  }
};
