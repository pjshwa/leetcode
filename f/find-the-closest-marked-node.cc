using pii = pair<int, int>;

class Solution {
public:
  int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
    vector<int> cdist(n, INT_MAX);
    vector<vector<pii>> adj(n);
    for (auto& e : edges) adj[e[0]].emplace_back(e[1], e[2]);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, s); cdist[s] = 0;
    while (!pq.empty()) {
      auto [dist, u] = pq.top(); pq.pop();
      if (cdist[u] < dist) continue;
      for (auto& [v, w] : adj[u]) {
        if (cdist[v] > dist + w) {
          cdist[v] = dist + w;
          pq.emplace(cdist[v], v);
        }
      }
    }

    int ans = INT_MAX;
    for (int u : marked) ans = min(ans, cdist[u]);
    if (ans == INT_MAX) ans = -1;
    return ans;
  }
};
