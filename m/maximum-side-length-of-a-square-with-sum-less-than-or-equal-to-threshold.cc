class Solution {
public:
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int N = mat.size(), M = mat[0].size();
    vector<vector<int>> P(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) {
      P[i][j] = mat[i - 1][j - 1] + P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
    }

    int l = 1, r = min(N, M) + 1;
    while (l < r) {
      int m = (l + r) / 2, ok = 0;
      for (int i = m; i <= N; ++i) for (int j = m; j <= M; ++j) {
        int sum = P[i][j] - P[i - m][j] - P[i][j - m] + P[i - m][j - m];
        ok |= (sum <= threshold);
      }
      if (ok) l = m + 1;
      else r = m;
    }
    return l - 1;
  }
};
