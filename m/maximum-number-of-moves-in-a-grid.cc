class Solution {
public:
  int maxMoves(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();
    vector<vector<int>> dp(N, vector<int>(M, -1));
    for (int i = 0; i < N; ++i) dp[i][0] = 0;

    int ans = 0;
    for (int j = 1; j < M; ++j) for (int i = 0; i < N; ++i) {
      for (int pi : {i - 1, i, i + 1}) {
        if (pi < 0 || pi >= N) continue;
        if (grid[i][j] <= grid[pi][j - 1]) continue;
        if (dp[pi][j - 1] == -1) continue;
        dp[i][j] = max(dp[i][j], dp[pi][j - 1] + 1);
      }
      ans = max(ans, dp[i][j]);
    }
    return ans;
  }
};
