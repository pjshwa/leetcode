class Solution {
public:
  int countMaxOrSubsets(vector<int>& nums) {
    int maxOr = 0, N = nums.size();
    for (int e : nums) maxOr |= e;

    int ans = 0;
    for (int s = 0; s < (1 << N); ++s) {
      int orSum = 0;
      for (int i = 0; i < N; ++i) {
        if (s & (1 << i)) orSum |= nums[i];
      }
      if (orSum == maxOr) ++ans;
    }
    return ans;
  }
};
