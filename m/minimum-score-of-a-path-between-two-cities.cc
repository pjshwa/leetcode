const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;

class Solution {
public:
  int minScore(int n, vector<vector<int>>& roads) {
    vector<pii> adj[n];
    for (auto& r : roads) {
      int u = r[0], v = r[1], w = r[2];
      u--; v--;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    int ans = INF;
    bool vis[n]; memset(vis, 0, sizeof(vis));
    function<void(int)> dfs = [&](int u) {
      vis[u] = true;
      for (auto& [v, w] : adj[u]) {
        ans = min(ans, w);
        if (!vis[v]) {
          vis[v] = true;
          dfs(v);
        }
      }
    };
    dfs(0);
    return ans;
  }
};
