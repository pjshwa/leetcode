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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    function<TreeNode*(int, int, int, int)> dfs = [&](int il, int ir, int pl, int pr) {
      if (il > ir) return (TreeNode*)nullptr;

      int root = postorder[pr];
      int k = il;
      while (inorder[k] != root) ++k;

      int left_size = k - il;
      TreeNode* node = new TreeNode(root);
      node->left = dfs(il, k - 1, pl, pl + left_size - 1);
      node->right = dfs(k + 1, ir, pl + left_size, pr - 1);
      return node;
    };

    int n = inorder.size();
    return dfs(0, n - 1, 0, n - 1);
  }
};
