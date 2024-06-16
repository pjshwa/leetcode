class Solution {
public:
  int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int N = nums.size(), ans = 0;
    for (int i = 0; i < N; ++i) ans = max(ans, nums[i] + nums[N - 1 - i]);
    return ans;
  }
};
