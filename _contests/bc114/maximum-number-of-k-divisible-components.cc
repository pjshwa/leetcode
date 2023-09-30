using ll = long long;

class Solution {
  vector<ll> ssz;
  vector<int> values;
  vector<vector<int>> adj;

  void dfs1(int v, int p) {
    ssz[v] = values[v];
    for (int u : adj[v]) {
      if (u == p) continue;
      dfs1(u, v);
      ssz[v] += ssz[u];
    }
  }

public:
  int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    ssz.resize(n); adj.resize(n);
    this->values = values;
    for (auto& e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs1(0, -1);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (ssz[i] % k == 0) ans++;
    }
    return ans;
  }
};
