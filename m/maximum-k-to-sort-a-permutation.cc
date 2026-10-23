class Solution {
public:
  int sortPermutation(vector<int>& nums) {
    int N = nums.size(), ans = -1;
    auto sorted = nums;
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < N; ++i) {
      if (nums[i] == sorted[i]) continue;
      if (ans == -1) ans = nums[i];
      else ans &= nums[i];
    }
    return ans == -1 ? 0 : ans;
  }
};
