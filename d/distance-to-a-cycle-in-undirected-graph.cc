const int MAXN = 1e5, INF = 0x3f3f3f3f;

class Solution {
  vector<int> adj[MAXN];
  int par[MAXN];
  bool vis[MAXN], is_cycle[MAXN];

  void dfs(int v, int p) {
    vis[v] = true; par[v] = p;
    for (int u : adj[v]) {
      if (vis[u]) {
        if (u == p || is_cycle[u]) continue;
        int g = v;
        while (g != u) {
          is_cycle[g] = true;
          g = par[g];
        }
        is_cycle[u] = true;
      }
      else dfs(u, v);
    }
  }

public:
  vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
    for (auto& e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }
    dfs(0, -1);

    queue<int> q;
    vector<int> cdist(n, INF);
    for (int i = 0; i < n; ++i) {
      if (!is_cycle[i]) continue;
      cdist[i] = 0; q.push(i);
    }

    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (int u : adj[v]) {
        if (cdist[u] == INF) {
          cdist[u] = cdist[v] + 1;
          q.push(u);
        }
      }
    }
    return cdist;
  }
};
