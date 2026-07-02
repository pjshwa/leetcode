#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

class Solution {
public:
  bool findSafeWalk(vector<vector<int>>& grid, int health) {
    int N = grid.size(), M = grid[0].size();
    vector<vector<int>> cdist(N, vector<int>(M, INT_MAX));
    deque<pair<int, int>> q;
    q.push_back({0, 0}); cdist[0][0] = grid[0][0];
    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop_front();
      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        int ndist = cdist[x][y] + grid[nx][ny];
        if (ndist < cdist[nx][ny]) {
          cdist[nx][ny] = ndist;
          if (grid[nx][ny] == 0) q.push_front({nx, ny});
          else q.push_back({nx, ny});
        }
      }
    }
    return cdist[N - 1][M - 1] < health;
  }
};
