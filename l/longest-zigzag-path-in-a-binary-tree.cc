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
  map<pair<TreeNode*, int>, int> d;
  int r(TreeNode* v, int p) {
    if (d.count({v, p})) return d[{v, p}];

    int ret = 0;
    if (p == 0 && v->left) ret = max(ret, 1 + r(v->left, 1));
    if (p == 1 && v->right) ret = max(ret, 1 + r(v->right, 0));

    return d[{v, p}] = ret;
  }

  int ans = 0;
  void l(TreeNode* v) {
    ans = max(ans, r(v, 0));
    ans = max(ans, r(v, 1));

    if (v->left) l(v->left);
    if (v->right) l(v->right);
  }

public:
  int longestZigZag(TreeNode* root) {
    l(root);
    return ans;
  }
};
