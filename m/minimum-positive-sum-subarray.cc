class Solution {
public:
  int minimumSumSubarray(vector<int>& nums, int l, int r) {
    int N = nums.size(), ans = INT_MAX;
    auto update = [&](int sum) {
      if (sum > 0 && sum < ans) ans = sum;
    };
    for (int d = l; d <= r; ++d) {
      int sum = 0;
      for (int i = 0; i < d; ++i) sum += nums[i];
      update(sum);
      for (int i = d; i < N; ++i) {
        sum += nums[i] - nums[i - d];
        update(sum);
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};
