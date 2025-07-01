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
  map<TreeNode*, int> sz, mem_min, mem_max, is_bst_c;

  bool dfs(TreeNode* node) {
    bool ok = true; int size = 1;
    mem_min[node] = mem_max[node] = node->val;
    if (node->left) {
      ok &= dfs(node->left) && mem_max[node->left] < node->val;
      mem_min[node] = min(mem_min[node], mem_min[node->left]);
      mem_max[node] = max(mem_max[node], mem_max[node->left]);
      size += sz[node->left];
    }
    if (node->right) {
      ok &= dfs(node->right) && mem_min[node->right] > node->val;
      mem_min[node] = min(mem_min[node], mem_min[node->right]);
      mem_max[node] = max(mem_max[node], mem_max[node->right]);
      size += sz[node->right];
    }
    sz[node] = size;
    return is_bst_c[node] = ok;
  }

public:
  int largestBSTSubtree(TreeNode* root) {
    if (root == nullptr) return 0;
    
    dfs(root); int ans = 0;
    for (auto& [node, is_bst] : is_bst_c) {
      if (is_bst) ans = max(ans, sz[node]);
    }
    return ans;
  }
};
