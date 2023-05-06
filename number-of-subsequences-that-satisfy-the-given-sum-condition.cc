using ll = long long;
const int MAX = 1e6, MOD = 1e9 + 7;

class Solution {
  int T[MAX + 1], P[MAX + 1];

  ll lpow(ll x, ll y, ll m) {
    ll r = 1;
    x %= m;
    while (y) {
      if (y & 1) r = (r * x) % m;
      x = (x * x) % m;
      y >>= 1;
    }
    return r;
  }

public:
  int numSubseq(vector<int>& nums, int target) {
    memset(T, 0, sizeof T);
    for (int e : nums) T[e]++;

    P[0] = 0;
    for (int i = 1; i <= MAX; i++) P[i] = P[i - 1] + T[i];

    int ans = 0;
    for (int i = 1; i <= MAX; i++) {
      if (2 * i > target) break;

      ll cur = lpow(2, T[i], MOD) - 1;
      cur = (cur * lpow(2, P[target - i] - P[i], MOD)) % MOD;
      ans = (ans + cur) % MOD;
    }
    return ans;
  }
};
