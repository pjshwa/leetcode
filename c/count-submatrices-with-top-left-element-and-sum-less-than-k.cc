class Solution {
public:
  int countSubmatrices(vector<vector<int>>& grid, int k) {
    int N = grid.size(), M = grid[0].size();
    vector<vector<int>> P(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) {
      P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + grid[i - 1][j - 1];
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) {
      ans += P[i][j] <= k;
    }
    return ans;
  }
};
