const int INF = 1e9;

class Solution {
public:
  int maxPathScore(vector<vector<int>>& grid, int k) {
    int N = grid.size(), M = grid[0].size(); k = min(k, N + M - 2);

    vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(k + 1, -INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      int v = grid[i][j];
      for (int s = v > 0; s <= k; ++s) {
        if (i > 0) dp[i][j][s] = max(dp[i][j][s], dp[i - 1][j][s - (v > 0)] + v);
        if (j > 0) dp[i][j][s] = max(dp[i][j][s], dp[i][j - 1][s - (v > 0)] + v);
      }
    }

    int ans = -1;
    for (int s = 0; s <= k; ++s) ans = max(ans, dp[N - 1][M - 1][s]);
    return ans;
  }
};
