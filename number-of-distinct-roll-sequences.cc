const int MOD = 1e9 + 7;

class Solution {
public:
  int distinctSequences(int n) {
    int dp[n + 1][7][7];
    memset(dp, 0, sizeof dp); dp[0][0][0] = 1;

    for (int i = 1; i <= n; ++i) {
      for (int prev_val1 = 0; prev_val1 <= 6; ++prev_val1) {
        for (int prev_val2 = 0; prev_val2 <= 6; ++prev_val2) {

          for (int next_val = 1; next_val <= 6; ++next_val) {
            if (next_val == prev_val1 || next_val == prev_val2) continue;
            if (prev_val1 > 0 && __gcd(prev_val1, next_val) != 1) continue;

            dp[i][next_val][prev_val1] = (
              dp[i][next_val][prev_val1] + dp[i - 1][prev_val1][prev_val2]
            ) % MOD;

          }

        }
      }
    }

    int ans = 0;
    for (int prev_val1 = 0; prev_val1 <= 6; ++prev_val1) {
      for (int prev_val2 = 0; prev_val2 <= 6; ++prev_val2) {
        ans = (ans + dp[n][prev_val1][prev_val2]) % MOD;
      }
    }
    return ans;
  }
};
