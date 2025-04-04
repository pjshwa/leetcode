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

 const int MAXN = 1000;

 class Solution {
   vector<TreeNode*> by_depth[MAXN + 1];
   vector<int> vis;
   map<TreeNode*, TreeNode*> parent;
 
   void dfs(TreeNode* node, int depth) {
     by_depth[depth].push_back(node);
     if (node->left) {
       parent[node->left] = node;
       dfs(node->left, depth + 1);
     }
     if (node->right) {
       parent[node->right] = node;
       dfs(node->right, depth + 1);
     }
   }
 
 public:
   TreeNode* lcaDeepestLeaves(TreeNode* root) {
     vis.resize(MAXN + 1, 0);
     dfs(root, 0);
 
     int d;
     for (d = MAXN; d >= 0; --d) if (!by_depth[d].empty()) break;
 
     queue<TreeNode*> q, nq;
     for (auto& node : by_depth[d]) q.push(node), vis[node->val] = 1;
 
     while (1) {
       if (q.size() == 1) return q.front();
 
       while (!q.empty()) {
         auto u = q.front(); q.pop();
         if (!vis[parent[u]->val]) vis[parent[u]->val] = 1, nq.push(parent[u]);
       }
       while (!nq.empty()) {
         auto u = nq.front(); nq.pop();
         q.push(u);
       }
     }
 
     return nullptr;
   }
 };
 