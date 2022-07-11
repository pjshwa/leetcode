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
  TreeNode* ans;

  void dfs(TreeNode* root, int target) {
    if (root == nullptr) return;
    if (root->val == target) {
      ans = root;
      return;
    }
    if (root->val > target) dfs(root->left, target);
    else dfs(root->right, target);
  }
public:
  TreeNode* searchBST(TreeNode* root, int val) {
    dfs(root, val);
    return ans;
  }
};
