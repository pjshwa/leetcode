class Solution {
  long long d[205][205];
  int n, m;
public:
  int sumRegion(int row1, int col1, int row2, int col2) {
    row1 = max(row1, 0), col1 = max(col1, 0);
    row2 = min(row2, n - 1), col2 = min(col2, m - 1);
    return d[row2 + 1][col2 + 1] - d[row2 + 1][col1] - d[row1][col2 + 1] + d[row1][col1];
  }
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    n = mat.size(), m = mat[0].size();
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      d[i + 1][j + 1] = d[i][j + 1] + d[i + 1][j] - d[i][j] + mat[i][j];
    }
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      vector<int> t;
      for (int j = 0; j < m; j++) t.push_back(sumRegion(i - k, j - k, i + k, j + k));
      ans.push_back(t);
    }
    return ans;
  }
};
