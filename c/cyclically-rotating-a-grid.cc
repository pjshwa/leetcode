#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
    int N = grid.size(), M = grid[0].size();
    for (int d = 0; 2 * d < min(N, M); ++d) {
      vector<int> V;
      for (int i = d; i < M - d; ++i) V.push_back(grid[d][i]);
      for (int i = d + 1; i < N - d; ++i) V.push_back(grid[i][M - d - 1]);
      for (int i = M - d - 2; i >= d; --i) V.push_back(grid[N - d - 1][i]);
      for (int i = N - d - 2; i > d; --i) V.push_back(grid[i][d]);

      int Z = (int)V.size(), p = 0;
      vector<int> W(Z);
      for (int i = 0; i < Z; ++i) W[i] = V[(i + k) % Z];
      for (int i = d; i < M - d; ++i) grid[d][i] = W[p++];
      for (int i = d + 1; i < N - d; ++i) grid[i][M - d - 1] = W[p++];
      for (int i = M - d - 2; i >= d; --i) grid[N - d - 1][i] = W[p++];
      for (int i = N - d - 2; i > d; --i) grid[i][d] = W[p++];
    }
    return grid;
  }
};
