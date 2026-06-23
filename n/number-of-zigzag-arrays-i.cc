#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2000, MOD = 1e9 + 7;

class Solution {
public:
  int zigZagArrays(int n, int l, int r) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(r + 1, 0)));
    for (int v = l; v <= r; ++v) {
      dp[1][0][v] = r - v;
      dp[1][1][v] = v - l;
    }
    for (int v = l; v <= r; ++v) {
      dp[1][0][v] = (dp[1][0][v] + dp[1][0][v - 1]) % MOD;
      dp[1][1][v] = (dp[1][1][v] + dp[1][1][v - 1]) % MOD;
    }

    for (int i = 2; i < n; ++i) {
      for (int v = l; v <= r; ++v) {
        if (v < r) dp[i][0][v] = (dp[i - 1][1][r] - dp[i - 1][1][v] + MOD) % MOD;
        if (v > l) dp[i][1][v] = (dp[i - 1][0][v - 1] - dp[i - 1][0][l - 1] + MOD) % MOD;
      }
      for (int v = l; v <= r; ++v) {
        dp[i][0][v] = (dp[i][0][v] + dp[i][0][v - 1]) % MOD;
        dp[i][1][v] = (dp[i][1][v] + dp[i][1][v - 1]) % MOD;
      }
    }
    return (dp[n - 1][0][r] + dp[n - 1][1][r]) % MOD;
  }
};
