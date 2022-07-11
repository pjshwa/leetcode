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
  vector<int> a1, a2;

  void dfs(TreeNode* node, int vid) {
    if (node->left) dfs(node->left, vid);
    vid == 1 ? a1.push_back(node->val) : a2.push_back(node->val);
    if (node->right) dfs(node->right, vid);
  }
public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    if (root1) dfs(root1, 1);
    if (root2) dfs(root2, 2);

    vector<int> ans;
    int s1 = 0, s2 = 0;
    while (s1 < a1.size() && s2 < a2.size()) {
      if (a1[s1] < a2[s2]) ans.push_back(a1[s1++]);
      else ans.push_back(a2[s2++]);
    }
    while (s1 < a1.size()) ans.push_back(a1[s1++]);
    while (s2 < a2.size()) ans.push_back(a2[s2++]);

    return ans;      
  }
};
