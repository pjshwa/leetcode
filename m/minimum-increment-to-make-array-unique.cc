class Solution {
public:
  int minIncrementForUnique(vector<int>& nums) {
    int N = nums.size(), ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < N; ++i) {
      int tar = max(nums[i], nums[i - 1] + 1);
      ans += tar - nums[i]; nums[i] = tar;
    }
    return ans;
  }
};
