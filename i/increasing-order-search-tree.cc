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
  vector<int> vals;
  void dfs(TreeNode* root) {
    if (!root) return;
    dfs(root->left);
    vals.push_back(root->val);
    dfs(root->right);
  }
public:
  TreeNode* increasingBST(TreeNode* root) {
    dfs(root);
    sort(vals.begin(), vals.end());
    TreeNode* ans = new TreeNode(0);
    TreeNode* cur = ans;
    for (int i = 0; i < vals.size(); i++) {
      cur->right = new TreeNode(vals[i]);
      cur = cur->right;
    }
    return ans->right;
  }
};
