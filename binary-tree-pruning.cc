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
  bool dfs(TreeNode* v) {
    int ret = v->val;
    if (v->left) {
      bool l = dfs(v->left);
      if (l) ret = true;
      else v->left = nullptr;
    }
    if (v->right) {
      bool r = dfs(v->right);
      if (r) ret = true;
      else v->right = nullptr;
    }
    return ret;
  }

public:
  TreeNode* pruneTree(TreeNode* root) {
    if (dfs(root)) return root;
    else return nullptr;
  }
};
