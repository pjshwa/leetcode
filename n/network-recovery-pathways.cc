#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

class Solution {
public:
  int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
    int N = online.size(), M = edges.size(), l = 0, r = 1e9 + 1;
    vector<vector<pii>> adj(N);
    for (auto& e : edges) {
      int u = e[0], v = e[1], w = e[2];
      if (!online[u] || !online[v]) continue;
      adj[u].emplace_back(v, w);
    }

    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    vector<ll> cdist(N);
    while (l < r) {
      int m = (l + r) / 2;

      fill(cdist.begin(), cdist.end(), LLONG_MAX);
      cdist[0] = 0; pq.emplace(0, 0);
      while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > cdist[u]) continue;
        for (auto& [v, w] : adj[u]) {
          if (w < m) continue;
          if (cdist[v] > d + w) {
            cdist[v] = d + w;
            pq.emplace(cdist[v], v);
          }
        }
      }
      if (cdist[N - 1] <= k) l = m + 1;
      else r = m;
    }
    return l - 1;
  }
};
