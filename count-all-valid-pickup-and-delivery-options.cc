const int MOD = 1e9 + 7;

class Solution {
public:
  int countOrders(int n) {
    long long ans = 1;
    for (int i = 1; i < n; i++) {
      long long t = 2 * i + 1;
      ans = (ans * ((t * (t + 1) / 2) % MOD)) % MOD;
    }
    return ans;
  }
};
