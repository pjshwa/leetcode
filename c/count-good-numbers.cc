using ll = long long;
const int MOD = 1e9 + 7;

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

class Solution {
public:
  int countGoodNumbers(long long n) {
    ll ans = lpow(20, n / 2, MOD);
    if (n & 1) ans = (ans * 5) % MOD;
    return ans;
  }
};
