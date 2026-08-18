#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<int> P;
  vector<vector<int>> dp;

  int rec(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    int ret = 0;
    for (int m = l; m < r; ++m) {
      int lsum = P[m + 1] - P[l], rsum = P[r + 1] - P[m + 1];
      if (lsum < rsum) ret = max(ret, lsum + rec(l, m));
      else if (lsum > rsum) ret = max(ret, rsum + rec(m + 1, r));
      else ret = max(ret, max(rec(l, m), rec(m + 1, r)) + lsum);
    }
    return dp[l][r] = ret;
  }

public:
  int stoneGameV(vector<int>& stoneValue) {
    int N = stoneValue.size();
    P.resize(N + 1);
    dp.assign(N, vector<int>(N, -1));
    for (int i = 0; i < N; ++i) P[i + 1] = P[i] + stoneValue[i];
    return rec(0, N - 1);
  }
};
