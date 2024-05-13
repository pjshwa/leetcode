class Solution {
public:
  int matrixScore(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();
    auto flip_row = [&](int i) {
      for (int j = 0; j < M; ++j) {
        grid[i][j] = 1 - grid[i][j];
      }
    };

    for (int i = 0; i < N; ++i) {
      if (grid[i][0] == 0) flip_row(i);
    }

    int ans = 0;
    for (int j = 0; j < M; ++j) {
      int ocnt = 0;
      for (int i = 0; i < N; ++i) ocnt += grid[i][j];
      int c = max(ocnt, N - ocnt);
      ans += c * (1 << (M - j - 1));
    }
    return ans;
  }
};
