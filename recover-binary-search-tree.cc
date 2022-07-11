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
  void recoverTree(TreeNode* root) {
    TreeNode *firstNode, *secondNode;
    stack<TreeNode*> s1;
    TreeNode *cur = root;
    TreeNode *pre = NULL;
    int count=0;
    while(cur!=NULL || s1.size()>0) {
      while(cur!=NULL) {
        s1.push(cur);
        cur=cur->left;
      }
      TreeNode * top = s1.top();
      if(pre!=NULL && pre->val>top->val) {
        if(count==0) {
          firstNode=pre;
          secondNode=top;
          count++;
        } else {
          secondNode=top;
        }
      }
      pre=top;
      s1.pop();
      cur=top->right;
    }
    swap(firstNode->val,secondNode->val);
  }
};
