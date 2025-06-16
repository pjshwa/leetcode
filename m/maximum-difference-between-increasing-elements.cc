class Solution {
public:
  int maximumDifference(vector<int>& nums) {
    int ans = nums[1] - nums[0], N = nums.size();
    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) {
      ans = max(ans, nums[j] - nums[i]);
    }
    return ans > 0 ? ans : -1;
  }
};
