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
  TreeNode* do_merge_trees(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return nullptr;

    int val = 0;
    if (t1) val += t1->val;
    if (t2) val += t2->val;

    auto left = do_merge_trees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
    auto right = do_merge_trees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);

    return new TreeNode(val, left, right);
  }
public:
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    return do_merge_trees(root1, root2);
  }
};
