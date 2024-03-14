/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int, ListNode*> t;
        auto cur = head; int dt=0;
        while (cur) t[dt]=cur,dt+=cur->val,cur=cur->next;
        if (dt==0) return nullptr;
        t[dt]=nullptr;
        
        cur=new ListNode(t[0]->val); dt=0;
        auto ans=cur;
        map<int,int>vis;vis[0]=1;
        while (1){
            dt+=t[dt]->val;
            if(vis.count(dt)||!t[dt]) break;
            vis[dt]=1;
            cur->next=new ListNode(t[dt]->val);
            cur=cur->next;
        }
        return ans;
    }
};
