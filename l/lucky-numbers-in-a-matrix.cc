class Solution {
public:
  vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    int N = matrix.size(), M = matrix[0].size();
    vector<int> rmin(N, INT_MAX), cmax(M, INT_MIN);
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      rmin[i] = min(rmin[i], matrix[i][j]);
      cmax[j] = max(cmax[j], matrix[i][j]);
    }

    vector<int> ans;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (matrix[i][j] == rmin[i] && matrix[i][j] == cmax[j]) {
        ans.push_back(matrix[i][j]);
      }
    }
    return ans;
  }
};
