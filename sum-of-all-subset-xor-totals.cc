class Solution {
public:
  int subsetXORSum(vector<int>& nums) {
    int N = nums.size(), ans = 0;
    for (int s = 0; s < (1 << N); ++s) {
      int x = 0;
      for (int i = 0; i < N; ++i) {
        if (s & (1 << i)) x ^= nums[i];
      }
      ans += x;
    }
    return ans;
  }
};
