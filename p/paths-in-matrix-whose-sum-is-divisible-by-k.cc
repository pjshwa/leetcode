const int MOD = 1e9 + 7;

class Solution {
public:
  int numberOfPaths(vector<vector<int>>& grid, int k) {
    int N = grid.size(), M = grid[0].size();
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(k, 0)));

    dp[0][0][grid[0][0] % k] = 1;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      for (int r = 0; r < k; ++r) {
        int pr = (r - (grid[i][j] % k) + k) % k;
        if (i > 0) dp[i][j][r] = (dp[i][j][r] + dp[i - 1][j][pr]) % MOD;
        if (j > 0) dp[i][j][r] = (dp[i][j][r] + dp[i][j - 1][pr]) % MOD;
      }
    }
    return dp[N - 1][M - 1][0];
  }
};
