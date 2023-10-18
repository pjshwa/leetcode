class Solution {
public:
  int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<int> adj[n];
    int dp[n], indegree[n];
    memset(dp, -1, sizeof dp);
    memset(indegree, 0, sizeof indegree);

    for (auto &r : relations) {
      int pre = r[0] - 1, nxt = r[1] - 1;
      adj[nxt].push_back(pre);
      ++indegree[pre];
    }

    // dfs(r) = min time to finish course r
    // = time[r] + max(dfs(nxt) for nxt in adj[r])
    function<int(int, int)> dfs = [&](int v, int p) {
      if (dp[v] != -1) return dp[v];

      int ret = 0;
      for (auto nxt : adj[v]) {
        if (nxt == p) continue;
        ret = max(ret, dfs(nxt, v));
      }
      return dp[v] = ret + time[v];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (indegree[i] == 0) ans = max(ans, dfs(i, -1));
    }
    return ans;
  }
};
