const int dx[2] = {0, -1}, dy[2] = {-1, 0};
const int MOD = 1e9 + 7;

class Solution {
public:
  int uniquePaths(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(2, 0)));
    for (int j = 1; j < M; ++j) {
      dp[0][j][0] = 1;
      if (grid[0][j] == 1) break;
    }
    for (int i = 1; i < N; ++i) {
      dp[i][0][1] = 1;
      if (grid[i][0] == 1) break;
    }
    for (int i = 1; i < N; ++i) for (int j = 1; j < M; ++j) for (int k = 0; k < 2; ++k) {
      int pi = i + dx[k], pj = j + dy[k];
      dp[i][j][k] = (dp[i][j][k] + dp[pi][pj][1 - k]) % MOD;
      if (grid[pi][pj] == 0) dp[i][j][k] = (dp[i][j][k] + dp[pi][pj][k]) % MOD;
    } 
    return (dp[N - 1][M - 1][0] + dp[N - 1][M - 1][1]) % MOD;
  }
};
