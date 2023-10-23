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
  TreeNode* correctBinaryTree(TreeNode* root) {
    set<TreeNode*> visited;
    queue<TreeNode*> q;
    q.push(root); visited.insert(root);

    // we will go level by level
    // if we find a node whose right child is in visited, we will remove it
    TreeNode* invalid = nullptr;
    while (!invalid) {
      queue<TreeNode*> nq;
      while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node->left) {
          nq.push(node->left);
          visited.insert(node->left);
        }
        if (node->right) {
          // this is the invalid node
          if (visited.find(node->right) != visited.end()) {
            invalid = node;
            break;
          }

          nq.push(node->right);
          visited.insert(node->right);
        }
      }
      q = nq;
    }

    q = queue<TreeNode*>();
    visited.clear();
    q.push(root); visited.insert(root);

    // now we will do a bfs again
    // if we find the invalid node, we will remove it
    while (!q.empty()) {
      TreeNode* node = q.front(); q.pop();
      if (node->left) {
        if (node->left == invalid) {
          node->left = nullptr;
          break;
        }
        q.push(node->left);
        visited.insert(node->left);
      }
      if (node->right) {
        if (node->right == invalid) {
          node->right = nullptr;
          break;
        }
        q.push(node->right);
        visited.insert(node->right);
      }
    }

    return root;
  }
};
