const int MOD = 1e9 + 7;

class Solution {
  int d[1001];
public:
  int numTilings(int n) {
    memset(d, 0, sizeof(d));
    d[1] = 1, d[2] = 2, d[3] = 5;
    for (int i = 4; i <= 1000; i++) {
      d[i] = (d[i] + d[i - 1]) % MOD;
      d[i] = (d[i] + d[i - 1]) % MOD;
      d[i] = (d[i] + d[i - 3]) % MOD;
    }
    return d[n];
  }
};
