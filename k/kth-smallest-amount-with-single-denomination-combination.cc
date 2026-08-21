#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
  ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

public:
  long long findKthSmallest(vector<int>& coins, int k) {
    ll N = coins.size(), l = 1, r = *min_element(coins.begin(), coins.end()) * (ll)k;
    while (l < r) {
      ll m = (l + r) / 2, sum = 0;
      for (int s = 0; s < (1 << N); ++s) {
        ll l = 1;
        for (int i = 0; i < N; ++i) if (s & (1 << i)) l = lcm(l, coins[i]);
        ll cnt = m / l;
        if (__builtin_popcount(s) % 2 == 0) cnt = -cnt;
        sum += cnt;
      }
      if (sum < k) l = m + 1;
      else r = m;
    }

    return l;
  }
};
