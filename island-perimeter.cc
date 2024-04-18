const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

class Solution {
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size(), ans = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (grid[i][j] == 0) continue;
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || x >= N || y < 0 || y >= M || grid[x][y] == 0) ++ans;
      }
    }
    return ans;
  }
};
