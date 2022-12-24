const int MAX = 1000, MOD = 1e9 + 7;

class Solution {
public:
  int numTilings(int n) {
    vector<int> d(MAX + 1, 0);
    d[1] = 1, d[2] = 2, d[3] = 5;
    for (int i = 4; i <= n; i++) {
      d[i] = (d[i] + d[i - 1]) % MOD;
      d[i] = (d[i] + d[i - 1]) % MOD;
      d[i] = (d[i] + d[i - 3]) % MOD;
    }
    return d[n];
  }
};
