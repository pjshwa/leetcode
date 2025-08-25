class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int N = mat.size(), M = mat[0].size();
    auto oob = [&] (int x, int y) {
      return x < 0 || x >= N || y < 0 || y >= M;
    };

    vector<int> res;
    for (int s = 0; s < N + M - 1; ++s) {
      int x = s, y = 0, d = 1;
      if (s & 1) swap(x, y), d = -1;
      while (oob(x, y)) x -= d, y += d;
      while (!oob(x, y)) {
        res.push_back(mat[x][y]);
        x -= d, y += d;
      }
    }
    return res;
  }
};
