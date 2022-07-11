class Solution {
public:
  int maxAncestorDiff(TreeNode* root) {
    result = 0;
    maxAncestorDiffUtil(root, 1e9, -1e9);
    return result;
  }

private:
  int result;
  void maxAncestorDiffUtil(TreeNode* node, int mn, int mx) {
    if (node == nullptr) return;
    int new_mn = min(mn, node->val);
    int new_mx = max(mx, node->val);
    result = max(result, new_mx - new_mn);

    maxAncestorDiffUtil(node->left, new_mn, new_mx);
    maxAncestorDiffUtil(node->right, new_mn, new_mx);

  }
};
