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
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    vector<TreeNode*> ans;
    map<string, int> t;

    function<string(TreeNode*)> dfs = [&](TreeNode* node) {
      if (!node) return string();

      string left = dfs(node->left);
      string right = dfs(node->right);
      string s = to_string(node->val) + "," + left + "," + right;

      if (t[s] == 1) ans.push_back(node);
      t[s]++;

      return s;
    };
    dfs(root);

    return ans;
  }
};
