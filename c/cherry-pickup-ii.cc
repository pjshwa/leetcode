class Solution {
  int d[70][4900];
public:
  int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m * m; j++) d[i][j] = -(1e9 + 7);
    }

    d[0][m - 1] = grid[0][0] + grid[0][m - 1];
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < m * m; j++) {
        int p1 = j / m, p2 = j % m;
        int addend = p1 == p2 ? grid[i][p1] : grid[i][p1] + grid[i][p2];
        for (int p1d = -1; p1d <= 1; p1d++) for (int p2d = -1; p2d <= 1; p2d++) {
          int p1n = (p1 + p1d), p2n = (p2 + p2d);
          if (p1n < 0 || p1n >= m || p2n < 0 || p2n >= m) continue;
          d[i][j] = max(d[i][j], d[i - 1][p1n * m + p2n] + addend);
        }
      }
    }

    return *max_element(d[n - 1], d[n - 1] + m * m);
  }
};
