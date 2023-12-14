class Solution {
public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();
    vector<int> R(N), C(M);
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      int v = grid[i][j];
      R[i] += v; C[j] += v;
    }

    vector<vector<int>> diff(N, vector<int>(M));
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      diff[i][j] = 2 * (R[i] + C[j]) - N - M;
    }
    return diff;
  }
};
