class Solution {
public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    int N = nums.size(); vector<int> ans(N, -1);
    for (int i = 0; i < N; ++i) {
      int e = nums[i];
      if (e % 2 == 0) continue;

      int b = 0;
      while ((1 << b) & e) ++b;
      ans[i] = e - (1 << (b - 1));
    }
    return ans;
  }
};
