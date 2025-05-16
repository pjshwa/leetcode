class Solution {
public:
  int maxKilledEnemies(vector<vector<char>>& grid) {
    int N = grid.size(), M = grid[0].size(), b;
    vector<vector<int>> P(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) {
      P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + (grid[i - 1][j - 1] == 'E');
    }

    vector<vector<int>> UB(N + 1, vector<int>(M + 1, 0)),
      DB(N + 1, vector<int>(M + 1, N)),
      LB(N + 1, vector<int>(M + 1, 0)),
      RB(N + 1, vector<int>(M + 1, M));
    for (int i = 1; i <= N; ++i) {
      b = 0;
      for (int j = 1; j <= M; ++j) {
        if (grid[i - 1][j - 1] == 'W') b = j;
        LB[i][j] = b;
      }
      b = M;
      for (int j = M; j >= 1; --j) {
        if (grid[i - 1][j - 1] == 'W') b = j;
        RB[i][j] = b;
      }
    }
    for (int j = 1; j <= M; ++j) {
      b = 0;
      for (int i = 1; i <= N; ++i) {
        if (grid[i - 1][j - 1] == 'W') b = i;
        UB[i][j] = b;
      }
      b = N;
      for (int i = N; i >= 1; --i) {
        if (grid[i - 1][j - 1] == 'W') b = i;
        DB[i][j] = b;
      }
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) {
      if (grid[i - 1][j - 1] != '0') continue;
      int u = UB[i][j], d = DB[i][j], l = LB[i][j], r = RB[i][j];
      int cur = P[d][j] - P[u][j] - P[d][j - 1] + P[u][j - 1] +
        P[i][r] - P[i][l] - P[i - 1][r] + P[i - 1][l];
      if (cur > ans) ans = cur;
    }
    return ans;
  }
};
  