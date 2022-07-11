/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
  vector<Node*> d2n[15];
  void dfs(Node* v, int d) {
    if (v == NULL) return;
    d2n[d].push_back(v);
    dfs(v->left, d + 1);
    dfs(v->right, d + 1);
  }
public:
  Node* connect(Node* root) {
    if (root == NULL) return NULL;
    dfs(root, 0);
    for (int d = 0; d < 15; d++) {
      if (d2n[d].size() == 0) break;
      for (int j = 0; j < d2n[d].size() - 1; j++) {
        d2n[d][j]->next = d2n[d][j + 1];
      }
    }
    return root;
  }
};
