const int MOD = 1e9 + 7;

class Solution {
public:
  int numOfArrays(int n, int m, int k) {
    int dp[n][m + 1][k + 1]; memset(dp, 0, sizeof dp);
    for (int j = 1; j <= m; ++j) dp[0][j][1] = 1;

    for (int i = 1; i < n; ++i) {
      for (int pj = 1; pj <= m; ++pj) for (int cj = 1; cj <= m; ++cj) {
        for (int l = 1; l <= k; ++l) {
          if (cj > pj && l == k) continue;

          int& cur = dp[i][max(cj, pj)][l + (cj > pj)];
          cur = (cur + dp[i - 1][pj][l]) % MOD;
        }
      }
    }

    int ans = 0;
    for (int j = 1; j <= m; ++j) ans = (ans + dp[n - 1][j][k]) % MOD;
    return ans;
  }
};
