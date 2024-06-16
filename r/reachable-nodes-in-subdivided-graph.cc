using pii = pair<int, int>;

class Solution {
public:
  int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    vector<pii> adj[n];
    for (auto &e : edges) {
      adj[e[0]].emplace_back(e[1], e[2] + 1);
      adj[e[1]].emplace_back(e[0], e[2] + 1);
    }

    int cdist[n]; memset(cdist, 0x3f, sizeof(cdist));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, 0); cdist[0] = 0;

    while (!pq.empty()) {
      auto [dist, u] = pq.top(); pq.pop();
      if (dist > cdist[u]) continue;
      for (auto &[v, w] : adj[u]) {
        if (dist + w < cdist[v]) {
          cdist[v] = dist + w;
          pq.emplace(dist + w, v);
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) ans += cdist[i] <= maxMoves;
    for (auto& e : edges) {
      int u = e[0], v = e[1], w = e[2];
      int ureach = max(0, maxMoves - cdist[u]);
      int vreach = max(0, maxMoves - cdist[v]);
      ans += min(w, ureach + vreach);
    }
    return ans;
  }
};
