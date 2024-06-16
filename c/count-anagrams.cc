using ll = long long;
const int MAX = 1e5, MOD = 1e9 + 7;

vector<string> split(const string &str, string delim) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(delim, start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));
    start = end + delim.size();
  }

  tokens.push_back(str.substr(start));
  return tokens;
}

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
  int countAnagrams(string s) {
    vector<ll> fac(MAX + 1), ifac(MAX + 1);
    fac[0] = 1;
    for (int i = 1; i <= MAX; i++) fac[i] = (fac[i - 1] * i) % MOD;
    ifac[MAX] = lpow(fac[MAX], MOD - 2);
    for (int i = MAX; i > 0; i--) ifac[i - 1] = (ifac[i] * i) % MOD;

    ll ans = 1;
    for (auto token : split(s, " ")) {
      vector<int> cnt(26);
      for (auto c : token) ++cnt[c - 'a'];

      ll sum = fac[token.size()];
      for (auto x : cnt) sum = (sum * ifac[x]) % MOD;
      ans = (ans * sum) % MOD;
    }

    return ans;
  }
};
