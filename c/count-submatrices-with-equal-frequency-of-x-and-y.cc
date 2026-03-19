class Solution {
public:
  int numberOfSubmatrices(vector<vector<char>>& grid) {
    int N = grid.size(), M = grid[0].size();
    vector<vector<int>> pX(N + 1, vector<int>(M + 1)), pY(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) {
      pX[i][j] = pX[i - 1][j] + pX[i][j - 1] - pX[i - 1][j - 1] + (grid[i - 1][j - 1] == 'X');
      pY[i][j] = pY[i - 1][j] + pY[i][j - 1] - pY[i - 1][j - 1] + (grid[i - 1][j - 1] == 'Y');
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) {
      int xc = pX[i][j], yc = pY[i][j];
      ans += (xc == yc && xc > 0);
    }
    return ans;
  }
};
