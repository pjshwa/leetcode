using ll = long long;

class Solution {
  ll upto(ll n) {
    ll u = 1, pw = 1, ret = 0;
    while (u * 4 <= n) {
      ret += 3 * u * pw;
      u *= 4; ++pw;
    }
    ret += (n - u + 1) * pw;
    return ret;
  }

public:
  long long minOperations(vector<vector<int>>& queries) {
    ll ans = 0;
    for (auto& q : queries) {
      ll cnt = upto(q[1]) - upto(q[0] - 1);
      ans += (cnt + 1) / 2;
    }
    return ans;
  }
};
