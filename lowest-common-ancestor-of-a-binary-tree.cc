/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
  map<TreeNode*, TreeNode*> parent;
  map<TreeNode*, int> depth;

  void dfs(TreeNode* node, TreeNode* p, int d) {
    if (node == nullptr) return;
    parent[node] = p;
    depth[node] = d;
    dfs(node->left, node, d + 1);
    dfs(node->right, node, d + 1);
  }

public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root, nullptr, 0);
    if (depth[p] > depth[q]) swap(p, q);
    while (depth[p] != depth[q]) q = parent[q];
    while (p != q) p = parent[p], q = parent[q];
    return p;
  }
};
