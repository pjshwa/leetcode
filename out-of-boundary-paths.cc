const int MOD = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

class Solution {
  int m, n;
  int d[50][50][51];
  int r(int i, int j, int c) {
    if (c == 0) return 0;
    if (d[i][j][c] != -1) return d[i][j][c];

    int res = 0;
    for (int k = 0; k < 4; k++) {
      int x = i + dx[k], y = j + dy[k];
      if (x < 0 || x >= m || y < 0 || y >= n) res = (res + 1) % MOD;
      else res = (res + r(x, y, c - 1)) % MOD;
    }

    return d[i][j][c] = res;
  }

public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    memset(d, -1, sizeof(d));
    this->m = m;
    this->n = n;
    return r(startRow, startColumn, maxMove);
  }
};
