class Solution {
public:
  int numSpecial(vector<vector<int>>& mat) {
    int N = mat.size(), M = mat[0].size();

    int ans = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (mat[i][j] == 0) continue;

      int rc = 0, cc = 0;
      for (int k = 0; k < N; ++k) rc += mat[k][j];
      for (int k = 0; k < M; ++k) cc += mat[i][k];
      if (rc == 1 && cc == 1) ++ans;
    }
    return ans;
  }
};
