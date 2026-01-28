const int INF = 0x3f3f3f3f;

class Solution {
public:
  int minCost(vector<vector<int>>& grid, int k) {
    int N = grid.size(), M = grid[0].size(), ans = INF;
    vector<vector<vector<int>>> dp(
        N, vector<vector<int>>(M, vector<int>(2, INF)));
    dp[0][0][0] = 0;

    vector<tuple<int, int, int, int>> T;
    for (int t = 0; t <= k; ++t) {
      int x = t % 2;
      for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
        if (i > 0) dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][x] + grid[i][j]);
        if (j > 0) dp[i][j][x] = min(dp[i][j][x], dp[i][j - 1][x] + grid[i][j]);
        ans = min(ans, dp[N - 1][M - 1][x]);
      }
      if (t == k) break;
      T.clear();

      for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
        dp[i][j][x ^ 1] = INF;
        T.emplace_back(-grid[i][j], dp[i][j][x], i, j);
      }
      sort(T.begin(), T.end()); int mval = INF;
      for (auto& [_, val, i, j] : T) {
        mval = min(mval, val);
        dp[i][j][x ^ 1] = min(dp[i][j][x ^ 1], mval);
      }
    }
    return ans;
  }
};
