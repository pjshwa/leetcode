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
class FindElements {
  set<int> E;

  void constructHelper(TreeNode* node, int val) {
    E.insert(val);
    if (node->left) {
      constructHelper(node->left, 2 * val + 1);
    }
    if (node->right) {
      constructHelper(node->right, 2 * val + 2);
    }
  }

public:
  FindElements(TreeNode* root) {
    constructHelper(root, 0);
  }
  
  bool find(int target) {
    return E.find(target) != E.end();
  }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
