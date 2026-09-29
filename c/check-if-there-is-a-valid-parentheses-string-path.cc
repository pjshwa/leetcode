#include <bits/stdc++.h>
using namespace std;

const int dx[2] = {1, 0}, dy[2] = {0, 1};

class Solution {
public:
  bool hasValidPath(vector<vector<char>>& grid) {
    if (grid[0][0] == ')') return false;
    int N = grid.size(), M = grid[0].size();
    auto oob = [&](int i, int j) {
      return i < 0 || i >= N || j < 0 || j >= M;
    };

    vector<vector<vector<int>>> vis(N, vector<vector<int>>(M, vector<int>(N + M + 1)));
    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 1}); vis[0][0][1] = 1;

    while (!Q.empty()) {
      auto [i, j, o] = Q.front(); Q.pop();
      for (int k = 0; k < 2; ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        if (oob(ni, nj)) continue;
        int no = o + (grid[ni][nj] == '(' ? 1 : -1);
        if (no < 0 || vis[ni][nj][no]) continue;
        vis[ni][nj][no] = 1; Q.push({ni, nj, no});
      }
    }
    return vis[N - 1][M - 1][0];
  }
};
