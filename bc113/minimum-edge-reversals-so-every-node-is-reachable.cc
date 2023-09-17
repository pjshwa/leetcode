using ll = long long;
using pii = pair<int, int>;

const int MAX = 1e5;
vector<pii> adj[MAX];
ll ssz[MAX], sval[MAX], dval[MAX];

class Solution {

  void dfs1(int v, int p) {
    ssz[v] = 1;
    for (auto& [u, _] : adj[v]) {
      if (u == p) continue;
      dfs1(u, v);
      ssz[v] += ssz[u];
    }
  }

  void dfs2(int v, int p) {
    sval[v] = 0;
    for (auto& [u, w] : adj[v]) {
      if (u == p) continue;
      dfs2(u, v);
      sval[v] += sval[u] + w;
    }
  }

  void dfs3(int v, int p, ll val) {
    dval[v] = val;
    for (auto& [u, w] : adj[v]) {
      if (u == p) continue;

      if (w == 0) dfs3(u, v, val + 1);
      else dfs3(u, v, val - 1);
    }
  }

public:
  vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
    for (int i = 0; i < n; ++i) adj[i].clear();

    for (auto& edge : edges) {
      int u = edge[0], v = edge[1];
      adj[u].push_back({v, 0});
      adj[v].push_back({u, 1});
    }

    int S = 0;
    dfs1(S, -1);
    dfs2(S, -1);
    dfs3(S, -1, sval[S]);

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      ans.push_back(dval[i]);
    }
    return ans;
  }
};
