const int MOD = 1e9 + 7;

class Solution {
public:
  int numWays(int steps, int arrLen) {
    arrLen = min(arrLen, steps);

    int dp[steps + 1][arrLen];
    memset(dp, 0, sizeof(dp)); dp[0][0] = 1;

    for (int step = 1; step <= steps; ++step) {
      for (int p = 0; p < arrLen; ++p) {
        for (int np : {p - 1, p, p + 1}) {
          if (np < 0 || np >= arrLen) continue;
          dp[step][np] = (dp[step][np] + dp[step - 1][p]) % MOD;
        }
      }
    }

    return dp[steps][0];
  }
};
