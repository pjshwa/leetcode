class Solution {
public:
  int findMaxK(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<>());
    int N = nums.size(), r = N - 1;
    for (int l = 0; l < N; ++l) {
      if (nums[l] <= 0) break;
      while (r >= 0 && -nums[r] > nums[l]) --r;
      if (nums[l] + nums[r] == 0) return nums[l];
    }
    return -1;
  }
};
