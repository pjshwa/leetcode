class Solution {
  int d[100][100];
public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int j = 0; j < n; j++) d[0][j] = matrix[0][j];
    for (int i = 1; i < n; i++) for (int j = 0; j < n; j++) {
      d[i][j] = 1e9;
      for (int jd = -1; jd <= 1; jd++) {
        int nj = j + jd;
        if (nj < 0 || nj >= n) continue;
        d[i][j] = min(d[i][j], d[i - 1][nj] + matrix[i][j]);
      }
    }
    return *min_element(d[n - 1], d[n - 1] + n);
  }
};
