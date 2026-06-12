#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

ll lpow(ll x, ll y, ll m) {
  ll r = 1;
  x %= m;
  while (y) {
    if (y & 1) r = (r * x) % m;
    x = (x * x) % m;
    y >>= 1;
  }
  return r;
}

class Solution {

public:
  int assignEdgeWeights(vector<vector<int>>& edges) {
    int N = edges.size() + 1;
    vector<int> adj[N];
    for (auto& e : edges) {
      int u = e[0] - 1, v = e[1] - 1;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    auto maxd = [&](int s) {
      queue<int> q; vector<int> cdist(N, -1);
      q.push(s); cdist[s] = 0;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) if (cdist[v] == -1) {
          cdist[v] = cdist[u] + 1;
          q.push(v);
        }
      }

      int maxv = *max_element(cdist.begin(), cdist.end());
      for (int i = 0; i < N; ++i) {
        if (cdist[i] == maxv) return pii(i, maxv);
      }
      return pii(-1, -1);
    };

    return lpow(2, maxd(0).second - 1, MOD);
  }
};
