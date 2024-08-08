const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

class Solution {
public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    auto oob = [&](int i, int j) {
      return i < 0 || i >= rows || j < 0 || j >= cols;
    };  

    vector<vector<int>> res;
    int ci = rStart, cj = cStart;
    for (int i = 0;; ++i) {
      int t = i / 2 + 1;
      for (int j = 0; j < t; ++j) {
        if (!oob(ci, cj)) res.push_back({ci, cj});
        ci += dx[i % 4]; cj += dy[i % 4];
      }
      if (res.size() == rows * cols) break;
    }
    return res;
  }
};
