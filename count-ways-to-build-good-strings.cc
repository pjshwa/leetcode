const int MOD = 1e9 + 7;

class Solution {
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    int d[high + 1]; d[0] = 1;
    for (int i = 1; i <= high; i++) {
      d[i] = 0;
      if (i >= zero) d[i] = (d[i] + d[i - zero]) % MOD;
      if (i >= one) d[i] = (d[i] + d[i - one]) % MOD;
    }

    int ans = 0;
    for (int i = low; i <= high; i++) ans = (ans + d[i]) % MOD;
    return ans;
  }
};
