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
  tuple<int, int, bool> r(TreeNode* node) {
    bool ok = true;
    int vmin = node->val, vmax = node->val;

    if (node->left) {
      auto [lmin, lmax, lok] = r(node->left);
      ok &= (lok && lmax < node->val);
      vmin = min(vmin, lmin);
      vmax = max(vmax, lmax);
    }
    if (node->right) {
      auto [rmin, rmax, rok] = r(node->right);
      ok &= (rok && rmin > node->val);
      vmin = min(vmin, rmin);
      vmax = max(vmax, rmax);
    }

    return {vmin, vmax, ok};
  }
public:
  bool isValidBST(TreeNode* root) {
    if (root == nullptr) return true;

    return get<2>(r(root));
  }
};
