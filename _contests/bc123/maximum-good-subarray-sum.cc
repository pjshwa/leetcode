using ll = long long;
const ll INF = 1e18;

class Solution {
public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    int N = nums.size();
    vector<ll> P(N + 1);
    for (int i = 1; i <= N; ++i) P[i] = P[i - 1] + nums[i - 1];

    map<int, int> t; ll ans = -INF;
    for (int i = 1; i <= N; ++i) {
      int e = nums[i - 1];
      if (t.count(e - k)) ans = max(ans, P[i] - P[t[e - k] - 1]);
      if (t.count(e + k)) ans = max(ans, P[i] - P[t[e + k] - 1]);

      if (t.count(e)) {
        int j = t[e];
        if (P[i] < P[j]) t[e] = i;
      }
      else t[e] = i;
    }

    if (ans == -INF) return 0;
    return ans;
  }
};
