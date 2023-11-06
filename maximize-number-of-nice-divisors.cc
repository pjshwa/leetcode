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
  int maxNiceDivisors(int primeFactors) {
    int rem3 = primeFactors % 3, div3 = primeFactors / 3;

    ll ans;
    if (rem3 == 1) {
      if (div3 == 0) ans = 1;
      else ans = (lpow(3, div3 - 1, MOD) * 4) % MOD;
    }
    else if (rem3 == 2) {
      ans = (lpow(3, div3, MOD) * 2) % MOD;
    }
    else {
      ans = lpow(3, div3, MOD);
    }
    return ans;
  }
};
