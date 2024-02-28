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
  int ans = 0;

public:
  int rec(TreeNode* node) {
    int maxl = 0, maxr = 0;
    if (node->left) maxl = rec(node->left) + 1;
    if (node->right) maxr = rec(node->right) + 1;
    ans = max(ans, maxl + maxr);
    return max(maxl, maxr);
  }

  int diameterOfBinaryTree(TreeNode* root) {
    rec(root);
    return ans;
  }
};
