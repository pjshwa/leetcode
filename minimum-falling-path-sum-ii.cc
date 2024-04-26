const int INF = 0x3f3f3f3f;

class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int N = grid.size();
    vector<vector<int>> dp(N, vector<int>(N, INF));
    for (int j = 0; j < N; ++j) dp[0][j] = grid[0][j];

    for (int i = 1; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < N; ++k) {
      if (j == k) continue;
      dp[i][j] = min(dp[i][j], dp[i - 1][k] + grid[i][j]);
    }

    return *min_element(dp[N - 1].begin(), dp[N - 1].end());
  }
};
