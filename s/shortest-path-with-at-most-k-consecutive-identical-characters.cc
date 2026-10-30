#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto& e : edges) adj[e[0]].emplace_back(e[1], e[2]);

    vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
    using T = tuple<int, int, int>; // (distance, node, consecutive_count)
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.emplace(0, 0, 1); dist[0][1] = 0;

    while (!pq.empty()) {
      auto [d, u, c] = pq.top(); pq.pop();
      if (d > dist[u][c]) continue;
      for (auto& [v, w] : adj[u]) {
        int nc = (labels[v] == labels[u]) ? c + 1 : 1;
        if (nc <= k && d + w < dist[v][nc]) {
          dist[v][nc] = d + w;
          pq.emplace(dist[v][nc], v, nc);
        }
      }
    }

    int ans = *min_element(dist[n - 1].begin(), dist[n - 1].end());
    if (ans == INT_MAX) return -1;
    return ans;
  }
};
