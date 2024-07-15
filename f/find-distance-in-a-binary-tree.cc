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
  map<int, int> lev, par;
  void dfs(TreeNode* node, int l) {
    lev[node->val] = l;
    if (node->left) {
      par[node->left->val] = node->val;
      dfs(node->left, l + 1);
    }
    if (node->right) {
      par[node->right->val] = node->val;
      dfs(node->right, l + 1);
    }
  }

public:
  int findDistance(TreeNode* root, int p, int q) {
    dfs(root, 0);
    int pl = lev[p], ql = lev[q], ans = 0;
    while (pl > ql) p = par[p], --pl, ++ans;
    while (pl < ql) q = par[q], --ql, ++ans;
    while (p != q) p = par[p], q = par[q], ans += 2;
    return ans;
  }
};
