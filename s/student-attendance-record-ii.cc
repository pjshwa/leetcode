const int MOD = 1e9 + 7;

class Solution {
public:
  int checkRecord(int n) {
    int dp[n + 1][2][3];
    memset(dp, 0, sizeof(dp)); dp[0][0][0] = 1;

    for (int i = 1; i <= n; ++i) {
      // 'A'
      for (int pl = 0; pl < 3; ++pl) dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][pl]) % MOD;

      // 'L'
      for (int pa = 0; pa < 2; ++pa) for (int pl = 0; pl < 2; ++pl) {
        dp[i][pa][pl + 1] = (dp[i][pa][pl + 1] + dp[i - 1][pa][pl]) % MOD;
      }

      // 'P'
      for (int pa = 0; pa < 2; ++pa) for (int pl = 0; pl < 3; ++pl) {
        dp[i][pa][0] = (dp[i][pa][0] + dp[i - 1][pa][pl]) % MOD;
      }
    }

    int ans = 0;
    for (int pa = 0; pa < 2; ++pa) for (int pl = 0; pl < 3; ++pl) {
      ans = (ans + dp[n][pa][pl]) % MOD;
    }
    return ans;
  }
};
