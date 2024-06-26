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
  vector<int> vals; int N;

  void dfs(TreeNode* node) {
    if (node == nullptr) return;
    dfs(node->left);
    vals.push_back(node->val);
    dfs(node->right);
  }

  TreeNode* build(int l, int r) {
    if (l >= r) return nullptr;
    int m = l + (r - l) / 2;
    TreeNode* node = new TreeNode(vals[m]);
    node->left = build(l, m);
    node->right = build(m + 1, r);
    return node;
  }

public:
  TreeNode* balanceBST(TreeNode* root) {
    dfs(root); N = vals.size();
    return build(0, N);
  }
};
