using ll = long long;
using pll = pair<ll, ll>;
const int MAX = 1e5;
const ll INF = 1e18;

class Solution {
  ll cdist[MAX + 1];
  vector<pll> graph[MAX + 1];

  void dijk(int s) {
    fill(cdist, cdist + MAX + 1, INF);
    cdist[s] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
      auto [wi, ui] = pq.top();
      pq.pop();

      if (wi > cdist[ui]) continue;

      for (auto &p : graph[ui]) {
        auto [vi, di] = p;
        if (cdist[vi] > di + wi) {
          cdist[vi] = di + wi;
          pq.push({cdist[vi], vi});
        }
      }
    }
  }

public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    for (auto& t : times) {
      int ui = t[0], vi = t[1], wi = t[2];
      graph[ui].push_back({vi, wi});
    }
    dijk(k);

    ll ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, cdist[i]);

    return ans == INF ? -1 : ans;
  }
};
