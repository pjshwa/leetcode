const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

class Solution {
public:
  double knightProbability(int n, int k, int row, int column) {
    double d[k + 1][n][n]; memset(d, 0, sizeof(d));

    d[0][row][column] = 1;
    for (int t = 1; t <= k; t++) {
      for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        for (int l = 0; l < 8; l++) {
          int x = i + dx[l], y = j + dy[l];
          if (x >= 0 && x < n && y >= 0 && y < n) {
            d[t][x][y] += d[t - 1][i][j] / 8;
          }
        }
      }
    }

    double ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ans += d[k][i][j];
    return ans;
  }
};
