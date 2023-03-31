const int MOD = 1e9 + 7;

class Solution {
  int d[50][50][10], P[51][51];
  int n, m;

  int r(int i, int j, int k) {
    if (d[i][j][k] != -1) return d[i][j][k];

    int sum = P[n][m] - P[i][m] - P[n][j] + P[i][j];
    if (k == 0) return d[i][j][k] = (sum > 0);

    int ret = 0;
    for (int x = i + 1; x < n; x++) {
      if (P[x][m] - P[i][m] - P[x][j] + P[i][j] > 0) {
        ret = (ret + r(x, j, k - 1)) % MOD;
      }
    }
    for (int y = j + 1; y < m; y++) {
      if (P[n][y] - P[i][y] - P[n][j] + P[i][j] > 0) {
        ret = (ret + r(i, y, k - 1)) % MOD;
      }
    }
    return d[i][j][k] = ret;
  }

public:
  int ways(vector<string>& pizza, int k) {
    this->n = pizza.size(), this->m = pizza[0].size();
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
      P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + (pizza[i - 1][j - 1] == 'A');
    }

    memset(d, -1, sizeof(d));
    return r(0, 0, k - 1);
  }
};
