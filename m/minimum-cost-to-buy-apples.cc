using ll = long long;
using T = pair<ll, int>;
const ll INF = 1e18;

class Solution {
public:
  vector<ll> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
    vector<pair<int, int>> adj[n];
    for (auto &r : roads) {
      int u = r[0] - 1, v = r[1] - 1, w = r[2];
      adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }

    vector<ll> ans(n);
    for (int i = 0; i < n; ++i) {
      vector<ll> cdist(n, INF);
      priority_queue<T, vector<T>, greater<T>> pq;
      pq.push({0, i}); cdist[i] = 0;

      while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (cdist[u] < d) continue;
        for (auto [v, w] : adj[u]) {
          if (cdist[v] > cdist[u] + w) {
            cdist[v] = cdist[u] + w;
            pq.push({cdist[v], v});
          }
        }
      }

      ll cost = INF;
      for (int j = 0; j < n; ++j) {
        if (cdist[j] == INF) continue;
        cdist[j] *= (k + 1);
        cdist[j] += appleCost[j];
        cost = min(cost, cdist[j]);
      }
      ans[i] = cost;
    }

    return ans;
  }
};
