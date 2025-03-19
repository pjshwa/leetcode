class Solution {
public:
  int minOperations(vector<int>& nums) {
    int N = nums.size(), ans = 0;
    for (int i = 0; i < N - 2; ++i) {
      if (nums[i] == 1) continue;
      for (int j = 0; j < 3; ++j) nums[i + j] ^= 1;
      ++ans;
    }
    if (!nums[N - 2] || !nums[N - 1]) ans = -1;
    return ans;
  }
};
