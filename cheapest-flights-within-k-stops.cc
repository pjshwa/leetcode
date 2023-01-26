const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<pii> adj[n];
    for (auto& f : flights) adj[f[0]].push_back({f[1], f[2]});

    int cdist[n][n];
    auto dijk = [&](int s) {
      for (int i = 0; i < n; i++) fill(cdist[i], cdist[i] + n, INF);

      priority_queue<tii, vector<tii>, greater<tii>> pq;
      pq.push({0, s, 0});

      while (!pq.empty()) {
        auto [wi, ui, ki] = pq.top(); pq.pop();
        if (wi > cdist[ui][ki]) continue;

        for (auto& [vi, di] : adj[ui]) {
          if (ki + 1 < n && cdist[vi][ki + 1] > di + wi) {
            cdist[vi][ki + 1] = di + wi;
            pq.push({cdist[vi][ki + 1], vi, ki + 1});
          }
        }
      }
    };
    dijk(src);

    int ans = INF;
    for (int i = 0; i <= k + 1 && i < n; i++) ans = min(ans, cdist[dst][i]);
    return ans == INF ? -1 : ans;
  }
};
