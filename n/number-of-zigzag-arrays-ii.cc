#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using matrix = vector<vector<ll>>;

const int MAXN = 150, MOD = 1e9 + 7;

matrix operator * (const matrix &a, const matrix &b) {
  int n = a.size();
  matrix c(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
    }
  }
  return c;
}

class Solution {
public:
  int zigZagArrays(int n, int l, int r) {
    r = r - l + 1; int V = 2 * r;
    matrix a = matrix(V, vector<ll>(V, 0));
    matrix ans = matrix(V, vector<ll>(V, 0));
    for (int i = 0; i < V; ++i) ans[i][i] = 1;

    auto get = [&](int v, int type) {
      return type * r + v;
    };
    for (int v = 0; v < r; ++v) {
      for (int j = v + 1; j < r; ++j) a[get(v, 1)][get(j, 0)] = 1;
      for (int j = 0; j < v; ++j) a[get(v, 0)][get(j, 1)] = 1;
    }

    n -= 2;
    while (n) {
      if (n & 1) ans = ans * a;
      a = a * a;
      n >>= 1;
    }

    ll res = 0;
    for (int i = 0; i < V; ++i) for (int v = 0; v < r; ++v) {
      res = (res + ans[i][get(v, 0)] * v % MOD) % MOD;
      res = (res + ans[i][get(v, 1)] * (r - v - 1) % MOD) % MOD;
    }
    return res;
  }
};
