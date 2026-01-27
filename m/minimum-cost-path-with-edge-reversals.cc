using pii = pair<int, int>;

class Solution {
public:
  int minCost(int n, vector<vector<int>>& edges) {
    vector<pii> adj[n];
    for (auto& e : edges) {
      int u = e[0], v = e[1], w = e[2];
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, 2 * w);
    }

    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, 0); dist[0] = 0;
    while (!pq.empty()) {
      auto [d, u] = pq.top(); pq.pop();
      if (d > dist[u]) continue;
      for (auto& [v, w] : adj[u]) {
        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          pq.emplace(dist[v], v);
        }
      }
    }

    int ans = dist[n - 1];
    return ans == INT_MAX ? -1 : ans;
  }
};
