using pii = pair<int, int>;

class Solution {
public:
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<pii> adj[n];
    for (auto& c : connections) {
      adj[c[0]].push_back({c[1], 1});
      adj[c[1]].push_back({c[0], 0});
    }

    function<int(int, int)> dfs = [&](int u, int p) {
      int ret = 0;
      for (auto& [v, w] : adj[u]) {
        if (v == p) continue;
        ret += dfs(v, u) + w;
      }
      return ret;
    };
    return dfs(0, -1);
  }
};
