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
  int goodNodes(TreeNode* root) {
    return goodNodesUtil(root, -1e9);
  }

private:
  int goodNodesUtil(TreeNode* root, int mx) {
    int good = root->val >= mx, l = 0, r = 0;
    if (root->left != nullptr) l = goodNodesUtil(root->left, max(mx, root->val));
    if (root->right != nullptr) r = goodNodesUtil(root->right, max(mx, root->val));
    return good + l + r;
  }
};
