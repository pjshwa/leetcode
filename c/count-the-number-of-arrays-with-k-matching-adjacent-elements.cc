using ll = long long;
const int MAXN = 1e5, MOD = 1e9 + 7;
ll fac[MAXN + 1], ifac[MAXN + 1];

ll lpow(ll x, ll y) {
  ll ans = 1;
  while (y) {
    if (y & 1) ans = (ans * x) % MOD;
    x = (x * x) % MOD;
    y >>= 1;
  }
  return ans;
}

class Solution {
public:
  int countGoodArrays(int n, int m, int k) {
    if (fac[0] != 1) {
      fac[0] = 1;
      for (int i = 1; i <= MAXN; i++) fac[i] = (fac[i - 1] * i) % MOD;
      ifac[MAXN] = lpow(fac[MAXN], MOD - 2);
      for (int i = MAXN; i > 0; i--) ifac[i - 1] = (ifac[i] * i) % MOD;
    }

    auto C = [&](int n, int k) {
      if (n < k || k < 0) return 0LL;
      return (fac[n] * ifac[k] % MOD) * ifac[n - k] % MOD;
    };

    ll ans = C(n - 1, k) * m % MOD;
    ans = ans * lpow(m - 1, n - 1 - k) % MOD;
    return ans;
  }
};
