#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
const int MAXN = 30, INF = 1e9 + 7;

class Solution {
  int dp[MAXN][MAXN][MAXN];

  int func(int x, int y, int mode) {
    return mode ? max(x, y) : min(x, y);
  }

  int get_type(int p, int f, int s) {
    if (p < f) return 1;
    if (p > s) return 3;
    return 2;
  }

  int rec(int n, int f, int s, int mode) {
    if (dp[n][f][s] != -1) return dp[n][f][s];

    int l = f + 1, r = n - s;
    if (l == r) return dp[n][f][s] = 1;

    int h = (n + 1) / 2;
    int c11 = 0, c22 = 0, c33 = 0, c12 = 0, c13 = 0, c23 = 0;
    for (int i = 0; i < h; ++i) {
      int l = i, r = n - 1 - i;
      if (l == f || l == s || r == f || r == s) continue;

      int lw = get_type(l, f, s), rw = get_type(r, f, s);
      if (lw == 1 && rw == 1) ++c11;
      if (lw == 1 && rw == 2) ++c12;
      if (lw == 1 && rw == 3) ++c13;
      if (lw == 2 && rw == 2) ++c22;
      if (lw == 2 && rw == 3) ++c23;
      if (lw == 3 && rw == 3) ++c33;
    }

    int ret = INF * (mode ? -1 : 1);
    for (int c1 = c11; c1 <= c11 + c13; ++c1) for (int c2 = c22; c2 <= c22 + c23; ++c2) {

      for (int d = 0; d <= c12; ++d) {
        int c1p = c1 + d, c2p = c2 + c12 - d;
        int c3p = h - c1p - c2p - 2;
        assert(c3p >= c33);
      
        ret = func(ret, rec(h, c1p, c1p + c2p + 1, mode) + 1, mode);
      }
    }

    return dp[n][f][s] = ret;
  }

public:
  vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
    --firstPlayer; --secondPlayer;
    vector<int> res;
    memset(dp, -1, sizeof(dp));
    res.push_back(rec(n, firstPlayer, secondPlayer, 0));
    memset(dp, -1, sizeof(dp));
    res.push_back(rec(n, firstPlayer, secondPlayer, 1));
    return res;
  }
};
