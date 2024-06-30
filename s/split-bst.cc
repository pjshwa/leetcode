class Solution {
public:
  vector<TreeNode*> splitBST(TreeNode* root, int target) {
    if (!root) return {nullptr, nullptr};

    if (root->val > target) {
      auto left = splitBST(root->left, target);
      root->left = left[1];
      return {left[0], root};
    } else {
      auto right = splitBST(root->right, target);
      root->right = right[0];
      return {root, right[1]};
    }
  }
};
