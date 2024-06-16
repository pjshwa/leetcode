using pii = pair<int, int>;

class Solution {
public:
  int longestPath(vector<int>& parent, string s) {
    int n = parent.size();

    vector<int> adj[n];
    for (int i = 1; i < n; ++i) {
      int u = parent[i], v = i;
      if (s[u] == s[v]) continue;

      adj[parent[i]].push_back(i);
      adj[i].push_back(parent[i]);
    }

    bool vis[n];
    function<pii(int, int)> maxd = [&](int v, int d) {
      vis[v] = true;

      int mv = v, md = d;
      for (int u : adj[v]) {
        if (!vis[u]) {
          auto [dv, dd] = maxd(u, d + 1);
          if (md < dd) md = dd, mv = dv;
        }
      }

      return pii(mv, md);
    };

    memset(vis, false, sizeof(vis));
    map<int, int> t;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        auto [v, d] = maxd(i, 0);
        t[i] = v;
      }
    }

    memset(vis, false, sizeof(vis));
    int ans = 0;
    for (auto [_, u] : t) {
      auto [v, d] = maxd(u, 0);
      ans = max(ans, d);
    }

    return ans + 1;
  }
};
