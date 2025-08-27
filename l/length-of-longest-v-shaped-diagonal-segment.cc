const int dx[4] = {-1, 1, 1, -1};
const int dy[4] = {1, 1, -1, -1};
const int MAXN = 500;

class Solution {
  int dp[MAXN][MAXN][4][2][2], N, M;

  bool oob(int i, int j) {
    return i < 0 || i >= N || j < 0 || j >= M;
  }

  int rec(int i, int j, int d, int o, int t, vector<vector<int>>& grid) {
    if (dp[i][j][d][o][t] != -1) return dp[i][j][d][o][t];

    int ret = 1, ni = i + dx[d], nj = j + dy[d];
    if (!oob(ni, nj) && grid[ni][nj] == (o ? 0 : 2)) {
      ret = 1 + rec(ni, nj, d, 1 - o, t, grid);
    }
    if (t == 0) {
      int nd = (d + 1) % 4;
      int ti = i + dx[nd], tj = j + dy[nd];
      if (!oob(ti, tj) && grid[ti][tj] == (o ? 0 : 2)) {
        ret = max(ret, 1 + rec(ti, tj, nd, 1 - o, 1, grid));
      }
    }

    return dp[i][j][d][o][t] = ret;
  }

public:
  int lenOfVDiagonal(vector<vector<int>>& grid) {
    N = grid.size(), M = grid[0].size();

    memset(dp, -1, sizeof dp); int ans = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (grid[i][j] != 1) continue;
      for (int d = 0; d < 4; ++d) {
        ans = max(ans, rec(i, j, d, 0, 0, grid));
      }
    }
    return ans;
  }
};
