using ll = long long;

class Solution {
public:
  long long maxSubarraySum(vector<int>& nums, int k) {
    int N = nums.size(); vector<ll> P(N + 1, 0);
    for (int i = 0; i < N; ++i) P[i + 1] = P[i] + nums[i];

    ll ans = LLONG_MIN;
    for (int si = 1; si <= k; ++si) {
      ll e = si + k - 1, run = 0;
      while (e <= N) {
        run += P[e] - P[e - k];
        ans = max(ans, run);
        if (run < 0) run = 0;
        e += k;
      }
    }
    return ans;
  }
};
