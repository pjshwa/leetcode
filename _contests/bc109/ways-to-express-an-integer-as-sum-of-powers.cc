const int MOD = 1e9 + 7;

class Solution {
  int d[301][301];
  vector<int> C;

  int r(int n, int i) {
    if (n == 0) return 1;
    if (i == C.size()) return 0;
    if (d[n][i] != -1) return d[n][i];

    int ret = r(n, i + 1);
    if (n >= C[i]) ret = (ret + r(n - C[i], i + 1)) % MOD;
    return d[n][i] = ret;
  }

public:
  int numberOfWays(int n, int x) {
    for (int i = 1;; i++) {
      int u = 1;
      for (int j = 0; j < x; j++) u *= i;
      if (u > n) break;
      C.push_back(u);
    }

    memset(d, -1, sizeof(d));
    return r(n, 0);
  }
};
