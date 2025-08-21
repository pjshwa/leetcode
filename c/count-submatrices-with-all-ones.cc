class Solution {
public:
  int numSubmat(vector<vector<int>>& mat) {
    int N = mat.size(), M = mat[0].size();
    vector<vector<int>> R(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
      int str = 0;
      for (int j = 0; j < M; ++j) {
        if (mat[i][j] == 1) ++str;
        else str = 0;
        R[i][j] = str;
      }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      int r = R[i][j];
      for (int pi = i; pi >= 0; --pi) {
        r = min(r, R[pi][j]);
        ans += r;
      }
    }
    return ans;
  }
};
