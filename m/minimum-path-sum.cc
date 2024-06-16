class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    int d[n + 1][m + 1];
    memset(d, 0x3f, sizeof(d)); d[0][1] = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
      d[i][j] = min(d[i - 1][j], d[i][j - 1]) + grid[i - 1][j - 1];
    }
    return d[n][m];
  }
};
