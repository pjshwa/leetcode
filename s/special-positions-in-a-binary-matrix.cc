class Solution {
public:
  int numSpecial(vector<vector<int>>& mat) {
    int N = mat.size(), M = mat[0].size();
    vector<int> rows(N), cols(M);
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (mat[i][j] == 0) continue;
      ++rows[i]; ++cols[j];
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) ++ans;
    }
    return ans;
  }
};
