#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e5, MOD = 1e9 + 7;
ll fac[MAXN + 1], ifac[MAXN + 1];

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

ll C(int n, int k) {
  if (n < k || k < 0) return 0LL;
  return (fac[n] * ifac[k] % MOD) * ifac[n - k] % MOD;
}

class Solution {

public:
  int assignEdgeWeights(vector<vector<int>>& edges) {
    if (fac[0] != 1) {
      fac[0] = 1;
      for (int i = 1; i <= MAXN; i++) fac[i] = (fac[i - 1] * i) % MOD;
      ifac[MAXN] = lpow(fac[MAXN], MOD - 2, MOD);
      for (int i = MAXN; i > 0; i--) ifac[i - 1] = (ifac[i] * i) % MOD;
    }

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

    int d = maxd(0).second, ans = 0;
    for (int i = 1; i <= d; i += 2) {
      ans = (ans + C(d, i)) % MOD;
    }
    return ans;
  }
};
