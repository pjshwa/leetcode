class Solution {
  int d[300][300];
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      if (matrix[i][j] == '0') d[i][j] = 0;
      else {
        d[i][j] = (i == 0 || j == 0) ? 1 : min(d[i - 1][j], min(d[i][j - 1], d[i - 1][j - 1])) + 1;
        ans = max(ans, d[i][j]);
      }
    }
    return ans * ans;
  }
};
