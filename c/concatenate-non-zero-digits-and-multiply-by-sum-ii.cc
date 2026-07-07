#include <bits/stdc++.h>
using namespace std;
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
  vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
    int N = s.size();
    vector<int> Ps(N + 1, 0), Pc(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
      Ps[i] = Ps[i - 1] + (s[i - 1] - '0');
      Pc[i] = Pc[i - 1] + (s[i - 1] != '0');
    }

    vector<ll> C(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
      char c = s[i - 1];
      if (c != '0') C[i] = (C[i - 1] * 10 + (c - '0')) % MOD;
      else C[i] = C[i - 1];
    }

    vector<int> ans;
    for (auto& q : queries) {
      int l = q[0] + 1, r = q[1] + 1;
      int sum = Ps[r] - Ps[l - 1];
      if (sum == 0) ans.push_back(0);
      else {
        ll pre = C[l - 1] * lpow(10, Pc[r] - Pc[l - 1], MOD) % MOD;
        ll num = (C[r] - pre + MOD) % MOD;
        ans.push_back(num * sum % MOD);
      }
    }
    return ans;
  }
};
