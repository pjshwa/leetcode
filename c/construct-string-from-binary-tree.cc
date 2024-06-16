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
  string ans;

  void dfs(TreeNode* v) {
    ans += to_string(v->val);
    if (v->left) {
      ans += '(';
      dfs(v->left);
      ans += ')';
      if (v->right) {
        ans += '(';
        dfs(v->right);
        ans += ')';
      }
    }
    else if (v->right) {
      ans += "()(";
      dfs(v->right);
      ans += ')';
    }
  }

public:
  string tree2str(TreeNode* root) {
    ans = "";
    dfs(root);
    return ans;
  }
};
