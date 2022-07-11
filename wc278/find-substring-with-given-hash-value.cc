using ll = long long;

class Solution {
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

  ll val(char c) {
    return c - 'a' + 1;
  }
public:
  string subStrHash(string s, int power, int modulo, int k, int hashValue) {
    int n = s.size();

    ll v = 0, p = 0;
    for (int i = n - k; i < n; i++) {
      v = (v + val(s[i]) * lpow(power, p, modulo)) % modulo;
      p++;
    }

    int ai = 1e9;
    if (v == hashValue) ai = n - k;

    for (int i = n - k - 1; i >= 0; i--) {
      v = (v - (val(s[i + k]) * lpow(power, p - 1, modulo) % modulo) + modulo) % modulo;
      v = (v * power + val(s[i])) % modulo;
      if (v == hashValue) ai = i;
    }

    return s.substr(ai, k);
  }
};
