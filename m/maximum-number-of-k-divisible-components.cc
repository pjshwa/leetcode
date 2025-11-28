class Solution {
public:
  int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    vector<int> S(n), adj[n];
    for (auto& e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v); adj[v].push_back(u);
    }

    function<void(int, int)> dfs = [&](int u, int p) {
      S[u] = values[u] % k;
      for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        S[u] = (S[u] + S[v]) % k;
      }
    };

    dfs(0, -1); int ans = 0;
    for (int i = 0; i < n; ++i) ans += (S[i] == 0);
    return ans;
  }
};
