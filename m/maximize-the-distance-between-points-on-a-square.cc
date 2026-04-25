#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  int maxDistance(int side, vector<vector<int>>& points, int k) {
    vector<ll> A; ll L = side;
    auto push = [&](ll x) {
      A.push_back(x);
      A.push_back(x + 4 * L);
    };
    for (auto& p : points) {
      int x = p[0], y = p[1];
      if (x == 0 || y == side) push(x + y);
      else if (x == side) push(3 * L - y);
      else push(4 * L - x);
    }
    sort(A.begin(), A.end());

    auto check = [&](ll d) {
      for (ll e : A) {
        ll cnt = 1, p = e;
        while (cnt < k && p < 4 * L) {
          auto it = upper_bound(A.begin(), A.end(), p + d - 1);
          if (it == A.end() || abs(e + 4 * L - *it) < d) break;
          p = *it; ++cnt;
        }
        if (cnt == k) return true;
      }
      return false;
    };

    ll l = 1, r = L + 1;
    while (l < r) {
      ll m = (l + r) / 2;
      if (check(m)) l = m + 1;
      else r = m;
    }
    return l - 1;
  }
};
