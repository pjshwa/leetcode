class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int r = 0, N = nums.size(), acc = 0, ans = N + 1;
    for (int l = 0; l < N; l++) {
      while (r < N && acc < target) acc += nums[r++];
      if (acc >= target) ans = min(ans, r - l);
      acc -= nums[l];
    }
    return ans == N + 1 ? 0 : ans;
  }
};
