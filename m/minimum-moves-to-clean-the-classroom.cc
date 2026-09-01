#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

class Solution {
public:
  int minMoves(vector<string>& classroom, int energy) {
    int si, sj, Lz = 0, N = classroom.size(), M = classroom[0].size();
    vector<vector<int>> f(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (classroom[i][j] == 'L') f[i][j] = 1 << (Lz++);
      if (classroom[i][j] == 'S') si = i, sj = j;
    }

    // i, j, mask, energy, moves
    using T = tuple<int, int, int, int, int>;
    vector<vector<vector<int>>> benergy(N, vector<vector<int>>(M, vector<int>(1 << Lz, -1)));
    queue<T> q; q.push({si, sj, 0, energy, 0});
    benergy[si][sj][0] = energy;

    while (!q.empty()) {
      auto [ci, cj, mask, e, moves] = q.front(); q.pop();
      if (mask == (1 << Lz) - 1) return moves;
      if (e == 0) continue;

      for (int d = 0; d < 4; ++d) {
        int ni = ci + dx[d], nj = cj + dy[d];
        if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;

        char c = classroom[ni][nj];
        if (c == 'X') continue;
        int ne = c == 'R' ? energy : e - 1;
        int nmask = mask | f[ni][nj];

        if (benergy[ni][nj][nmask] >= ne) continue;
        benergy[ni][nj][nmask] = ne;
        q.push({ni, nj, nmask, ne, moves + 1});
      }
    }
    return -1;
  }
};
