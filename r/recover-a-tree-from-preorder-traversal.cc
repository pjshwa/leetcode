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

 using pii = pair<int, int>;

 class Solution {
 public:
   TreeNode* recoverFromPreorder(string traversal) {
     int N = traversal.size(), i = 0;
 
     function<pii()> read = [&]() -> pii {
       int level = 0, val = 0;
       while (i < N && traversal[i] == '-') ++i, ++level;
       while (i < N && traversal[i] != '-') {
         val = val * 10 + traversal[i] - '0';
         i++;
       }
       return {level, val};
     };
 
     auto [_, val] = read();
     vector<TreeNode*> tree;
     tree.push_back(new TreeNode(val));
 
     while (i < N) {
       auto [level, val] = read();
       while (tree.size() > level) tree.pop_back();
 
       auto node = new TreeNode(val);
       if (tree.back()->left == nullptr) tree.back()->left = node;
       else tree.back()->right = node;
       tree.push_back(node);
     }
 
     return tree[0];
   }
 };
 