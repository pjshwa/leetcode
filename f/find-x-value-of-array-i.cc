#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
  vector<ll> nums, ans; int N;

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

  ll nC2(ll n) {
    return n * (n - 1) / 2;
  }

  void solve_k4() {
    map<int, int> T;
    for (int k : {1, 3}) {
      T.clear(); T[1] = 1;
      ll p = 1;
      for (ll e : nums) {
        if (e % 2 == 0) T.clear(), T[1] = 1, p = 1;
        else {
          p = (p * e) % 4;
          ans[k] += T[(p * k) % 4];
          ++T[p];
        }
      }
    }

    ll l = 0, str = 0;
    for (ll e : nums) {
      if (e == 0) {
        ans[2] += l * (str + 1);
        l = str = 0;
      }
      else if (e % 2 == 0) {
        ans[2] += l * (str + 1);
        l = str + 1; str = 0;
      }
      else ++str;
    }
    ans[2] += l * (str + 1);
    ans[0] = nC2(N + 1) - ans[1] - ans[2] - ans[3];
  }

  void solve_kprime(int m) {
    int invs[m];
    for (int i = 1; i < m; ++i) invs[i] = lpow(i, m - 2, m);

    // solve k = 0
    ll str = 0; ans[0] = nC2(N + 1);
    for (ll e : this->nums) {
      if (e == 0) ans[0] -= nC2(str + 1), str = 0;
      else ++str;
    }
    ans[0] -= nC2(str + 1);

    map<int, int> T;
    for (int k = 1; k < m; ++k) {
      T.clear(); T[1] = 1;
      ll p = 1;
      for (ll e : nums) {
        if (e == 0) T.clear(), T[1] = 1, p = 1;
        else {
          p = (p * e) % m;
          ans[k] += T[(p * invs[k]) % m];
          ++T[p];
        }
      }
    }
  }

public:
  vector<long long> resultArray(vector<int>& nums, int k) {
    N = nums.size(); this->nums.clear();
    for (int e : nums) this->nums.push_back(e % k);
    ans.assign(k, 0);

    if (k == 4) solve_k4();
    else solve_kprime(k);
    return ans;
  }
};
