class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    int d[n][m];
    memset(d, 0, sizeof(d));

    d[0][0] = obstacleGrid[0][0] ? 0 : 1;
    for (int i = 1; i < m; i++) {
      d[0][i] = obstacleGrid[0][i] ? 0 : d[0][i - 1];
    }
    for (int i = 1; i < n; i++) {
      d[i][0] = obstacleGrid[i][0] ? 0 : d[i - 1][0];
    }
    for (int i = 1; i < n; i++) for (int j = 1; j < m; j++) {
      d[i][j] = obstacleGrid[i][j] ? 0 : d[i - 1][j] + d[i][j - 1];
    }

    return d[n - 1][m - 1];
  }
};
