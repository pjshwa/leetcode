const int INF = 0x3f3f3f3f;

class Solution {
public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();

    int max_sum = -INF, min_sum = INF, max_run = 0, min_run = 0, total = 0;
    for (int i = 0; i < n; i++) {
      max_run = max(max_run + nums[i], nums[i]);
      max_sum = max(max_sum, max_run);

      min_run = min(min_run + nums[i], nums[i]);
      min_sum = min(min_sum, min_run);

      total += nums[i];
    }

    if (max_sum < 0) return max_sum;
    return max(max_sum, total - min_sum);
  }
};
