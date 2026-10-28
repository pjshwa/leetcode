class Solution {
public:
  int minCost(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(1 << 10, 0)));
    dp[0][0][grid[0][0]] = 1;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) for (int k = 0; k < (1 << 10); ++k) {
      if (i > 0) dp[i][j][k] |= dp[i - 1][j][k ^ grid[i][j]];
      if (j > 0) dp[i][j][k] |= dp[i][j - 1][k ^ grid[i][j]];
    }
    for (int k = 0; k < (1 << 10); ++k) if (dp[N - 1][M - 1][k]) return k;
    return -1;
  }
};
