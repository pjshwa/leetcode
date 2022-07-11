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
  int minJumps(vector<int>& arr) {
    map<int, vector<int>> u;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      u[arr[i]].push_back(i);
      if (i < n - 1) graph[i].push_back({i + 1, 1});
      if (i > 0) graph[i].push_back({i - 1, 1});
    }

    int it = 50000;
    for (auto& [a, v] : u) {
      for (int e : v) {
        graph[it].push_back({e, 1});
        graph[e].push_back({it, 0});
      }
      it++;
    }

    dijk(0);
    return cdist[n - 1];
  }
};
