class NumMatrix {
  long long d[205][205];
public:
  NumMatrix(vector<vector<int>>& matrix) {
    memset(d, 0, sizeof(d));
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      d[i + 1][j + 1] = d[i][j + 1] + d[i + 1][j] - d[i][j] + matrix[i][j];
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return d[row2 + 1][col2 + 1] - d[row2 + 1][col1] - d[row1][col2 + 1] + d[row1][col1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
