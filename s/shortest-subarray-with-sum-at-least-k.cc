using ll = long long;
using pll = pair<ll, ll>;

class Solution {
public:
  int shortestSubarray(vector<int>& nums, int k) {
    ll sum = 0, len = 0, N = nums.size(), ans = N + 1;
    deque<pll> dq;
    for (int e : nums) {
      if (!dq.empty() && e <= 0) {
        auto& [v, c] = dq.back();
        v += e; ++c;
      } else {
        dq.push_back({e, 1});
      }
      while (dq.size() >= 2 && dq.back().first <= 0) {
        auto& [v, c] = dq.back(); dq.pop_back();
        auto& [u, d] = dq.back();
        u += v; d += c;
      }

      sum += e; ++len;
      if (sum <= 0) {
        sum = 0; len = 0;
        dq.clear();
      }

      while (!dq.empty() && sum - dq.front().first >= k) {
        auto& [v, c] = dq.front();
        sum -= v; len -= c;
        dq.pop_front();
      }
      if (sum >= k) ans = min(ans, len);
    }

    if (ans == N + 1) ans = -1;
    return ans;
  }
};
