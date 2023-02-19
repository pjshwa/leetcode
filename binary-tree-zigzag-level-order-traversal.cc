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

const int MAX = 2000;

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<int> by_level[MAX];

    function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int l) {
      if (!node) return;
      by_level[l].push_back(node->val);
      dfs(node->left, l + 1);
      dfs(node->right, l + 1);
    };
    dfs(root, 0);

    for (int i = 1; i < MAX; i += 2) {
      reverse(by_level[i].begin(), by_level[i].end());
    }

    vector<vector<int>> ans;
    for (int i = 0; i < MAX; i++) {
      if (by_level[i].empty()) break;
      ans.push_back(by_level[i]);
    }
    return ans;
  }
};
