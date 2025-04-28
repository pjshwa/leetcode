using ll = long long;

class Solution {
public:
  long long countSubarrays(vector<int>& nums, long long k) {
    int N = nums.size(); vector<ll> P(N + 1);
    for (int i = 1; i <= N; ++i) P[i] = P[i - 1] + nums[i - 1];

    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
      int l = i, r = N + 1;
      while (l < r) {
        int m = (l + r) / 2;
        int cnt = m - i + 1;
        if (cnt * (P[m] - P[i - 1]) < k) l = m + 1;
        else r = m;
      }
      ans += l - i;
    }
    return ans;
  }
};
