const int MOD = 1e9 + 7;

class Solution {
public:
  int countOrders(int n) {
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
      long long cur = i * (2 * i - 1);
      ans = (ans * cur) % MOD;
    }
    return ans;
  }
};
