const int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

class Solution {
public:
  int shortestPathAllKeys(vector<string>& grid) {
    int n = grid.size(), m = grid[0].size(), K = 0;
    int si, sj;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      int val = grid[i][j];
      if (val == '@') si = i, sj = j;
      if ('a' <= val && val <= 'f') K = max(K, val - 'a' + 1);
    }

    int cdist[n][m][64]; memset(cdist, -1, sizeof cdist);
    queue<tuple<int, int, int>> q;
    q.emplace(si, sj, 0); cdist[si][sj][0] = 0;

    while (!q.empty()) {
      auto [i, j, s] = q.front(); q.pop();
      if (s == (1 << K) - 1) return cdist[i][j][s];

      for (int k = 0; k < 4; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

        int val = grid[ni][nj];
        if ('a' <= val && val <= 'f') {
          int ns = s | (1 << (val - 'a'));
          if (cdist[ni][nj][ns] == -1) {
            cdist[ni][nj][ns] = cdist[i][j][s] + 1;
            q.emplace(ni, nj, ns);
          }
        }
        else {
          if ('A' <= val && val <= 'F') {
            if (!(s & (1 << (val - 'A')))) continue;
          }
          if (val == '#') continue;
          if (cdist[ni][nj][s] != -1) continue;

          cdist[ni][nj][s] = cdist[i][j][s] + 1;
          q.emplace(ni, nj, s);
        }
      }
    }

    return -1;
  }
};
