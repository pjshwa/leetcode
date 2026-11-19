class Solution {
public:
  int minimizeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int N = nums.size(), ans = INT_MAX;
    for (int i = 0; i < 3; ++i) {
      ans = min(ans, nums[N + i - 3] - nums[i]);
    }
    return ans;
  }
};
