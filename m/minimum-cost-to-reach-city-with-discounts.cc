class Solution {
public:
  int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
    vector<pair<int, int>> adj[n];
    for (auto& vv : highways) {
      int u = vv[0], v = vv[1], w = vv[2];
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, w);
    }

    using T = tuple<int, int, int>;
    vector<vector<int>> cdist(n, vector<int>(discounts + 1, INT_MAX));
    priority_queue<T, vector<T>, greater<T>> pq;
    cdist[0][0] = 0; pq.emplace(0, 0, 0);

    while (!pq.empty()) {
      auto [d, u, k] = pq.top(); pq.pop();
      if (cdist[u][k] < d) continue;
      for (auto [v, w] : adj[u]) {
        if (cdist[v][k] > cdist[u][k] + w) {
          cdist[v][k] = cdist[u][k] + w;
          pq.emplace(cdist[v][k], v, k);
        }
        if (k < discounts && cdist[v][k + 1] > cdist[u][k] + w / 2) {
          cdist[v][k + 1] = cdist[u][k] + w / 2;
          pq.emplace(cdist[v][k + 1], v, k + 1);
        }
      }
    }

    int ans = *min_element(cdist[n - 1].begin(), cdist[n - 1].end());
    if (ans == INT_MAX) ans = -1;
    return ans;
  }
};
