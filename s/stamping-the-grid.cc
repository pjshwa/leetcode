class Solution {
public:
  bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
    int N = grid.size(), M = grid[0].size();

    int P[N + 10][M + 10]; memset(P, 0, sizeof P);
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) {
      P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + grid[i - 1][j - 1];
    }

    int V[N + 10][M + 10]; memset(V, 0, sizeof V);
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) {
      int x = i + stampHeight - 1, y = j + stampWidth - 1;
      if (x > N || y > M) continue;

      int rsum = P[x][y] - P[x][j - 1] - P[i - 1][y] + P[i - 1][j - 1];
      if (rsum) continue;

      V[i][j] += 1; V[x + 1][y + 1] += 1;
      V[x + 1][j] -= 1; V[i][y + 1] -= 1;
    }

    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) {
      V[i][j] += V[i - 1][j] + V[i][j - 1] - V[i - 1][j - 1];
      if (V[i][j] == 0 && grid[i - 1][j - 1] == 0) return false;
    }
    return true;
  }
};
