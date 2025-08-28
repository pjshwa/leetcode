class Solution {
public:
  vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    int N = grid.size();
    auto oob = [&](int x, int y) {
      return x < 0 || x >= N || y < 0 || y >= N;
    };
    
    vector<int> R;
    for (int i = 0; i < 2 * N - 2; ++i) {
      {
        int x = N - 1 - i, y = 0;
        while (oob(x, y)) ++x, ++y;
        while (!oob(x, y)) R.push_back(grid[x++][y++]);
      }
      if (i < N) sort(R.begin(), R.end());
      else sort(R.begin(), R.end(), greater<int>());
      {
        int x = N - 1 - i, y = 0;
        while (oob(x, y)) ++x, ++y;
        while (!oob(x, y)) grid[x++][y++] = R.back(), R.pop_back();
      }
    }
    return grid;
  }
};
