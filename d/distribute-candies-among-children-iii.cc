using ll = long long;

class Solution {
  int n, limit;

  ll sum_range(int l, int r) {
    if (l > r) return 0;
    return (ll)(r - l + 1) * (l + r) / 2;
  }

  ll f(int x) {
    int rem = n - x;
    int l = max(0, rem - limit), u = min(rem, limit);
    return max(0, u - l + 1);
  }

public:
  ll distributeCandies(int n, int limit) {
    limit = min(n, limit);
    this->n = n; this->limit = limit;

    ll ans;
    if (n < 2 * limit) {
      ans = sum_range(f(0), f(n - limit)) + sum_range(f(limit), f(n - limit + 1));
    } else {
      ans = sum_range(f(0), f(limit));
    }
    return ans;
  }
};
