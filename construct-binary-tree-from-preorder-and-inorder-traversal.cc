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
  map<int, int> inv;
  TreeNode* ans;
  vector<int> preorder;

  TreeNode* dfs(int psi, int pei, int isi, int iei) {
    if (psi == pei) return nullptr;

    int ri = inv[preorder[psi]];
    TreeNode* cur = new TreeNode(preorder[psi]);

    int lgap = ri - isi, rgap = iei - ri - 1;
    if (lgap) cur->left = dfs(psi + 1, psi + lgap + 1, isi, ri);
    if (rgap) cur->right = dfs(pei - rgap, pei, ri + 1, iei);

    return cur;
  }

public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    this->preorder = preorder;
    for (int i = 0; i < n; ++i) inv[inorder[i]] = i;
    return dfs(0, n, 0, n);
  }
};
