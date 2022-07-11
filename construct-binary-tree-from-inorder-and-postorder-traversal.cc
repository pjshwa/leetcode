// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
  TreeNode* buildNode(int is, int ie, int ps, int pe, vector<int>& inorder, vector<int>& postorder) {
    TreeNode *node = new TreeNode(postorder[pe]);

    // Find root position in inorder array
    int pos = is;
    while (inorder[pos] != postorder[pe]) pos++;

    if (pos > is) node->left = buildNode(is, pos - 1, ps, pos - (is - ps) - 1, inorder, postorder);
    if (pos < ie) node->right = buildNode(pos + 1, ie, pos - (is - ps), pe - 1, inorder, postorder);

    return node;
  }

  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    if (n) return buildNode(0, n - 1, 0, n - 1, inorder, postorder);
    else return nullptr;
  }
};
