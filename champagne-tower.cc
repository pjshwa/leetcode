class Solution {
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    double dp[100][100]{}; dp[0][0] = poured;
    for (int i = 0; i < query_row; ++i) for (int j = 0; j <= i; ++j) {
      double fall = max(0.0, dp[i][j] - 1.0) / 2;
      dp[i + 1][j] += fall;
      dp[i + 1][j + 1] += fall;
    }
    return min(1.0, dp[query_row][query_glass]);
  }
};
