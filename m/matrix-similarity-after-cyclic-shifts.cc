class Solution {
public:
  bool areSimilar(vector<vector<int>>& mat, int k) {
    int N = mat.size(), M = mat[0].size();
    k %= M;
    for (int i = 0; i < N; ++i) {
      int rot = i % 2 ? k : M - k;
      for (int j = 0; j < M; ++j) {
        if (mat[i][j] != mat[i][(j + rot) % M]) return false;
      }
    }
    return true;
  }
};
