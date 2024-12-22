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

  void dfs(TreeNode* node, int l) {
    if (node == nullptr) return;
    depth[node] = l;
    if (node->left != nullptr) parent[node->left] = node, dfs(node->left, l + 1);
    if (node->right != nullptr) parent[node->right] = node, dfs(node->right, l + 1);
  }

public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root, 0);
    if (!depth.count(p) || !depth.count(q)) return nullptr;
    while (p != q) {
      if (depth[p] > depth[q]) p = parent[p];
      else if (depth[p] < depth[q]) q = parent[q];
      else p = parent[p], q = parent[q];
    }
    return p;
  }
};
