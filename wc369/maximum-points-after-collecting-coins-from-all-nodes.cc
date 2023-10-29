const int INF = 0x3f3f3f3f;

class Solution {
public:
  int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
    int n = coins.size();

    vector<int> adj[n];
    for (auto& e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int dp[n][30]; memset(dp, -1, sizeof dp);

    // vertex u, "halving" l times used.
    function<int(int, int, int)> dfs = [&](int u, int l, int p) {
      if (dp[u][l] != -1) return dp[u][l];

      int val = coins[u];
      for (int i = 0; i < l; ++i) val /= 2;

      int ret = -INF;
      // collect using first method
      {
        int cur = val - k;
        for (int v : adj[u]) {
          if (v == p) continue;
          cur += dfs(v, l, u);
        }
        ret = max(ret, cur);
      }

      // collect using second method
      {
        int cur = val / 2;
        for (int v : adj[u]) {
          if (v == p) continue;
          cur += dfs(v, min(l + 1, 29), u);
        }
        ret = max(ret, cur);
      }

      return dp[u][l] = ret;
    };

    return dfs(0, 0, -1);
  }
};
