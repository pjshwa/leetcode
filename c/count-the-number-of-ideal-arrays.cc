using ll = long long;
const int MAXN = 1e4 + 40, MAXP = 40, MOD = 1e9 + 7;
ll C[MAXN + 1][MAXP + 1];

class Solution {
  void init() {
    C[0][0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
      C[i][0] = 1;
      for (int j = 1; j <= MAXP; ++j) {
        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
      }
    }
  }

public:
  int idealArrays(int n, int maxValue) {
    init();

    int ans = 0;
    for (int i = 1; i <= maxValue; ++i) {
      ll num = i, cur = 1;
      for (int q = 2; q * q <= num; ++q) {
        int cnt = 0;
        while (num % q == 0) num /= q, ++cnt;
        cur = (cur * C[n + cnt - 1][cnt]) % MOD;
      }
      if (num > 1) cur = (cur * n) % MOD;
      ans = (ans + cur) % MOD;
    }
    return ans;
  }
};
