const int MAXV = 1e5;

class Solution {
public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    vector<int> Va(MAXV + 1, 0); int vcnt = 0, N = nums.size();
    auto inc = [&](int v, int d) {
      if (Va[v] == 0) ++vcnt;
      Va[v] += d;
      if (Va[v] == 0) --vcnt;
    };

    long long ans = 0, sum = 0;
    for (int i = 0; i < k; ++i) inc(nums[i], 1), sum += nums[i];
    if (vcnt == k) ans = sum;

    for (int i = k; i < N; ++i) {
      inc(nums[i - k], -1); inc(nums[i], 1);
      sum += nums[i] - nums[i - k];
      if (vcnt == k) ans = max(ans, sum);
    }
    return ans;
  }
};
