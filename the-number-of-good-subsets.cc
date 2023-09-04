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
  int numberOfGoodSubsets(vector<int>& nums) {
    int C[31]{};
    for (int e : nums) C[e]++;

    vector<int> candidates = {2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 21, 22, 26, 30};
    int Z = candidates.size();

    ll ans = 0;
    for (int state = 0; state < (1 << Z); state++) {
      ll num = 1;
      for (int i = 0; i < Z; i++) {
        if (state & (1 << i)) num *= candidates[i];
      }

      bool able = true;
      for (int f : {2, 3, 5, 7, 11, 13}) {
        int cnt = 0;
        while (num % f == 0) num /= f, cnt++;
        able &= (cnt <= 1);
      }
      if (!able) continue;

      ll ways = 1;
      for (int i = 0; i < Z; i++) {
        if (state & (1 << i)) ways = (ways * C[candidates[i]]) % MOD;
      }
      ans = (ans + ways) % MOD;
    }

    // for these primes, we can choose either none or one of them respectively
    for (int p : {17, 19, 23, 29}) ans = (ans * (C[p] + 1)) % MOD;

    // subtract one case of choosing none
    ans = (ans - 1 + MOD) % MOD;

    // we can choose 1 as many as we want
    ans = (ans * lpow(2, C[1], MOD)) % MOD;

    return ans;
  }
};
