class Solution {
public:
  int twoSumLessThanK(vector<int>& nums, int k) {
    int ans = -1, N = nums.size();
    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) {
      int sum = nums[i] + nums[j];
      if (sum < k) ans = max(ans, sum);
    }
    return ans;
  }
};
