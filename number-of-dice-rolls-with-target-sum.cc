const int MOD = 1e9 + 7;

class Solution {
public:
  int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(2, vector<int>(target + 1));
    dp[0][0] = 1;

    for (int l = 1; l <= n; ++l) {
      int x = l % 2;
      for (int v = 0; v <= target; ++v) dp[x][v] = 0;
      for (int i = 1; i <= k; ++i) for (int v = i; v <= target; ++v) {
        dp[x][v] = (dp[x][v] + dp[1 - x][v - i]) % MOD;
      }
    }

    return dp[n % 2][target];
  }
};
