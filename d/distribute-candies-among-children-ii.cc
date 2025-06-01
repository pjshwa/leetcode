using ll = long long;

class Solution {
public:
  ll distributeCandies(int n, int limit) {
    ll ans = 0; limit = min(n, limit);
    for (int p1 = 0; p1 <= limit; ++p1) {
      int rem = n - p1;
      // p2 takes [rem - limit, limit] candies
      int p2_min = max(0, rem - limit), p2_max = min(rem, limit);
      if (p2_min <= p2_max) ans += p2_max - p2_min + 1;
    }
    return ans;
  }
};
