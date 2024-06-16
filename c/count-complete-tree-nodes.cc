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
public:
  int countNodes(TreeNode* root) {
    if (!root) return 0;

    TreeNode* node = root; int lev = -1;
    while (node) {
      node = node->left;
      lev++;
    }

    int left = 0, right = 1 << lev;
    while (left < right) {
      int mid = (left + right) / 2;

      TreeNode* node = root;
      for (int i = lev - 1; i >= 0; i--) {
        if (mid & (1 << i)) node = node->right;
        else node = node->left;
      }

      if (node) left = mid + 1;
      else right = mid;
    }

    return (1 << lev) - 1 + left;
  }
};
