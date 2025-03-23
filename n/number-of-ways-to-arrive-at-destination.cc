using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

class Solution {
  vector<ll> cdist, dp;
  vector<vector<pii>> adj;

  int rec(int v) {
    if (v == 0) return 1;
    if (dp[v] != -1) return dp[v];

    int ret = 0;
    for (auto& [u, w] : adj[v]) {
      if (cdist[u] + w == cdist[v]) {
        ret = (ret + rec(u)) % MOD;
      }
    }
    return dp[v] = ret;
  }

public:
  int countPaths(int n, vector<vector<int>>& roads) {
    cdist.assign(n, LLONG_MAX); adj.resize(n);
    for (auto& road : roads) {
      int u = road[0], v = road[1], w = road[2];
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, w);
    }

    using T = tuple<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.emplace(0, 0); cdist[0] = 0;
    while (!pq.empty()) {
      auto [d, u] = pq.top(); pq.pop();
      if (d > cdist[u]) continue;
      for (auto& [v, w] : adj[u]) {
        if (cdist[v] > d + w) {
          cdist[v] = d + w;
          pq.emplace(d + w, v);
        }
      }
    }

    dp.assign(n, -1);
    return rec(n - 1);
  }
};
