const int INF = 0x3f3f3f3f;

class Solution {
public:
  int maximumAmount(vector<vector<int>>& coins) {
    int N = coins.size(), M = coins[0].size();
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(3, -INF)));

    for (int k = 1; k < 3; ++k) dp[0][0][k] = 0;
    dp[0][0][0] = coins[0][0];

    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (i == 0 && j == 0) continue;

      for (int k = 0; k < 3; ++k) {
        if (i > 0) {
          dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + coins[i][j]);
          if (k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
        }
        if (j > 0) {
          dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + coins[i][j]);
          if (k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1]);
        }
      }
    }
    return max({dp[N - 1][M - 1][0], dp[N - 1][M - 1][1], dp[N - 1][M - 1][2]});
  }
};
