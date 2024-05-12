class Solution {
public:
  vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int N = grid.size();
    vector<vector<int>> ans(N - 2, vector<int>(N - 2));
    for (int i = 0; i < N - 2; ++i) for (int j = 0; j < N - 2; ++j) {
      int max_val = 0;
      for (int x = 0; x < 3; ++x) for (int y = 0; y < 3; ++y) {
        max_val = max(max_val, grid[i + x][j + y]);
      }
      ans[i][j] = max_val;
    }
    return ans;
  }
};
