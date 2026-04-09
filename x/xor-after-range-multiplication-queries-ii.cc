const int KLIM = 400, MOD = 1e9 + 7;
using ll = long long;
using pii = pair<int, int>;

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
  int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    vector<tuple<int, int, int>> U[KLIM]; int N = nums.size();
    for (auto& q : queries) {
      ll l = q[0], r = q[1], k = q[2], x = q[3];
      if (k < KLIM) U[k].emplace_back(l, r, x);
      else {
        for (int i = l; i <= r; i += k) nums[i] = (nums[i] * x) % MOD;
      }
    }

    vector<ll> P(N);
    for (int k = 1; k < KLIM; ++k) {
      P.assign(N, 1);
      for (auto& [l, r, x] : U[k]) {
        P[l] = (P[l] * x) % MOD;
        int rr = l + ((r - l) / k) * k + k;
        if (rr < N) P[rr] = (P[rr] * lpow(x, MOD - 2, MOD)) % MOD;
      }
      for (int s = 0; s < k; ++s) {
        ll p = 1;
        for (int i = s; i < N; i += k) {
          p = (p * P[i]) % MOD;
          nums[i] = (nums[i] * p) % MOD;
        }
      }
    }

    int ans = 0;
    for (int x : nums) ans ^= x;
    return ans;
  }
};
