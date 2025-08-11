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
  vector<int> productQueries(int n, vector<vector<int>>& queries) {
    ll e = 0; vector<ll> Es;
    while (n) {
      if (n & 1) Es.push_back(e);
      n >>= 1;
      e++;
    }
    int Z = Es.size();
    for (int i = 1; i < Z; ++i) Es[i] += Es[i - 1];

    vector<int> ans;
    for (auto& q : queries) {
      int l = q[0], r = q[1];
      ll e = Es[r] - (l ? Es[l - 1] : 0);
      ans.push_back(lpow(2, e, MOD));
    }
    return ans;
  }
};
