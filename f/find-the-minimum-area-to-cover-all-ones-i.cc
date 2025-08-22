class Solution {
public:
  int minimumArea(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();
    int lx = N, ux = 0, ly = M, uy = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (!grid[i][j]) continue;
      lx = min(lx, i), ux = max(ux, i);
      ly = min(ly, j), uy = max(uy, j);
    }
    return (ux - lx + 1) * (uy - ly + 1);
  }
};
