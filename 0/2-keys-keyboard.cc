class Solution {
public:
  int minSteps(int n) {
    int dp[n + 1][n + 1];
    memset(dp, 0x3f, sizeof(dp));

    queue<pair<int, int>> Q;
    Q.push({1, 0}); dp[1][0] = 0;

    int ans = 0x3f3f3f3f;
    while (!Q.empty()) {
      auto [c, p] = Q.front(); Q.pop();
      if (c == n) ans = min(ans, dp[c][p]);

      // Copy
      if (dp[c][c] > dp[c][p] + 1) {
        dp[c][c] = dp[c][p] + 1;
        Q.push({c, c});
      }

      // Paste
      if (c + p <= n && dp[c + p][p] > dp[c][p] + 1) {
        dp[c + p][p] = dp[c][p] + 1;
        Q.push({c + p, p});
      }
    }

    return ans;
  }
};
