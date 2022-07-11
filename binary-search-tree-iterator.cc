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
class BSTIterator {
  stack<TreeNode*> st;
public:
  BSTIterator(TreeNode* root) {
    auto cur = root;
    st.push(root);
    while (cur->left) {
      st.push(cur->left);
      cur = cur->left;
    }
  }

  int next() {
    TreeNode* cur = st.top();
    TreeNode* right = cur->right;
    int res = cur->val;

    st.pop();
    if (right) {
      cur = right;
      st.push(cur);
      while (cur->left) {
        st.push(cur->left);
        cur = cur->left;
      }
    }
    return res;
  }

  bool hasNext() {
    return !st.empty();
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
