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

const int MAXN = 1000;

class Solution {
  int D[MAXN + 1];
  vector<TreeNode*> roots;

  void dfs(TreeNode* node) {
    int val = node->val;
    if (node->left) {
      dfs(node->left);
      int lval = node->left->val;
      if (D[lval]) node->left = nullptr;
      if (D[val] && !D[lval]) roots.push_back(node->left);
    }
    if (node->right) {
      dfs(node->right);
      int rval = node->right->val;
      if (D[rval]) node->right = nullptr;
      if (D[val] && !D[rval]) roots.push_back(node->right);
    }
  }

public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    memset(D, 0, sizeof D); D[0] = 1;
    for (int e : to_delete) D[e] = 1;

    TreeNode* dummy = new TreeNode(0, root, nullptr);
    dfs(dummy);
    return roots;
  }
};
