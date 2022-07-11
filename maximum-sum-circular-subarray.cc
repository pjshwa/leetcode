
class Solution {
public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size(), sum = 0;
    for (int i = 0; i < n; i++) sum += nums[i];

    int max_so_far = -1e9, max_ending_here = 0;
    for (int i = 0; i < n; i++) {
      max_ending_here = max_ending_here + nums[i];
      if (max_so_far < max_ending_here) max_so_far = max_ending_here;
      if (max_ending_here < 0) max_ending_here = 0;
    }
    int a = max_so_far;
    if (a < 0) return a;

    max_so_far = -1e9, max_ending_here = 0;
    for (int i = 0; i < n; i++) {
      max_ending_here = max_ending_here - nums[i];
      if (max_so_far < max_ending_here) max_so_far = max_ending_here;
      if (max_ending_here < 0) max_ending_here = 0;
    }
    return max(sum + max_so_far, a);
  }
};
