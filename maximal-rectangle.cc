class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int N = matrix.size(), M = matrix[0].size();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    auto L = dp;

    for (int i = 1; i <= N; ++i) {
      L[i][1] = matrix[i - 1][0] == '1';
      for (int j = 2; j <= M; ++j) {
        L[i][j] = matrix[i - 1][j - 1] == '1' ? L[i][j - 1] + 1 : 0;
      }
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) {
      if (matrix[i - 1][j - 1] == '0') continue;
      int width = L[i][j];
      for (int k = i; k >= 1; --k) {
        width = min(width, L[k][j]);
        ans = max(ans, width * (i - k + 1));
      }
    }
    return ans;
  }
};
