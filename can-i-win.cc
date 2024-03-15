int dp[1<<20][2];

class Solution {
    //unordered_map<tuple<int,int,int>,bool> cache;
    int n,k;
    
    bool dfs(int s,int t,int p){
        //if (cache.count({s,t,p})) return cache[{s
        if (dp[s][p]!=-1)return dp[s][p];
        if (t>=k) return false;
        
        bool ret=false;
        for (int i=0;i<n;i++){
            if(s&(1<<i)) continue;
            ret|=!dfs(s^(1<<i),t+1+i,1-p);
        }
        return dp[s][p]=ret;
    }
    
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        n=maxChoosableInteger;
        k=desiredTotal;
        if (n*n+n<2*k) return false;
        if (k==0) return true;
        
        memset(dp,-1,sizeof dp);
        return dfs(0,0,0);
    }
};
