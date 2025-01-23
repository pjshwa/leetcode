class Solution {
public:
  int countServers(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();
    vector<int> Rcnt(N), Ccnt(M);
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      Rcnt[i] += grid[i][j];
      Ccnt[j] += grid[i][j];
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (Rcnt[i] > 1 || Ccnt[j] > 1) ans += grid[i][j];
    }
    return ans;
  }
};
