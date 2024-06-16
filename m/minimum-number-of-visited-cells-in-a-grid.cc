const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;

class Solution {
public:
  int minimumVisitedCells(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();

    priority_queue<pii, vector<pii>, greater<pii>> mRow[N];
    priority_queue<pii, vector<pii>, greater<pii>> mCol[M];

    int dp[N][M];
    memset(dp, 0x3f, sizeof(dp)); dp[0][0] = 1;
    mRow[0].push({1, grid[0][0]}); mCol[0].push({1, grid[0][0]});

    for (int j = 1; j < M; ++j) {
      while (!mRow[0].empty() && mRow[0].top().second < j) mRow[0].pop();
      if (!mRow[0].empty()) {
        dp[0][j] = min(dp[0][j], mRow[0].top().first + 1);
      }
      mRow[0].push({dp[0][j], j + grid[0][j]});
      mCol[j].push({dp[0][j], grid[0][j]});
    }

    for (int i = 1; i < N; ++i) {
      while (!mCol[0].empty() && mCol[0].top().second < i) mCol[0].pop();
      if (!mCol[0].empty()) {
        dp[i][0] = min(dp[i][0], mCol[0].top().first + 1);
      }
      mRow[i].push({dp[i][0], grid[i][0]});
      mCol[0].push({dp[i][0], i + grid[i][0]});

      for (int j = 1; j < M; ++j) {
        while (!mRow[i].empty() && mRow[i].top().second < j) mRow[i].pop();
        while (!mCol[j].empty() && mCol[j].top().second < i) mCol[j].pop();
        if (!mRow[i].empty()) {
          dp[i][j] = min(dp[i][j], mRow[i].top().first + 1);
        }
        if (!mCol[j].empty()) {
          dp[i][j] = min(dp[i][j], mCol[j].top().first + 1);
        }
        mRow[i].push({dp[i][j], j + grid[i][j]});
        mCol[j].push({dp[i][j], i + grid[i][j]});
      }
    }

    int ans = dp[N - 1][M - 1];
    if (ans == INF) ans = -1;
    return ans;
  }
};
