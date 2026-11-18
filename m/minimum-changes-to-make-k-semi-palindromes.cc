#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200, INF = 0x3f3f3f3f;
int dpk[MAXN + 1][MAXN + 1], dps[MAXN + 1][MAXN + 1];

class Solution {
  string S;

  int getCount(int s, int e, int d) {
    int len = e - s + 1, ret = 0;
    if (len == d) return INF;
    for (int i = 0; i < d; ++i) {
      int l = s + i, r = e - (d - 1 - i);
      while (l < r) {
        if (S[l] != S[r]) ++ret;
        l += d; r -= d;
      }
    }
    return ret;
  }

  int getMinCount(int s, int e) {
    if (dps[s][e] != -1) return dps[s][e];
    int len = e - s + 1, ret = INF;
    for (int f = 1; f * f <= len; ++f) {
      if (len % f) continue;
      ret = min(ret, getCount(s, e, f));
      ret = min(ret, getCount(s, e, len / f));
    }
    return dps[s][e] = ret;
  }

public:
  int minimumChanges(string s, int k) {
    this->S = s;
    memset(dps, -1, sizeof(dps));
    memset(dpk, 0x3f, sizeof(dpk));

    int N = s.size(); dpk[0][0] = 0;
    for (int i = 1; i <= N; ++i) for (int j = 0; j < i; ++j) for (int t = 1; t <= k; ++t) {
      dpk[i][t] = min(dpk[i][t], dpk[j][t - 1] + getMinCount(j, i - 1));
    }
    return dpk[N][k];
  }
};
