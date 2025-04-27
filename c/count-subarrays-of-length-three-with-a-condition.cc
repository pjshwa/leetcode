class Solution {
public:
  int countSubarrays(vector<int>& nums) {
    int N = nums.size(), ans = 0;
    for (int i = 0; i < N - 2; ++i) {
      int a = nums[i], b = nums[i + 1], c = nums[i + 2];
      if (b == a + c + a + c) ++ans;
    }
    return ans;
  }
};
