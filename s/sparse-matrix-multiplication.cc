class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
    int N = mat1.size(), M = mat1[0].size(), K = mat2[0].size();
    vector<vector<int>> ans(N, vector<int>(K, 0));
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) for (int k = 0; k < K; ++k) {
      ans[i][k] += mat1[i][j] * mat2[j][k];
    }
    return ans;
  }
};
