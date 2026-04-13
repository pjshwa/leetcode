class Solution {
public:
  int getMinDistance(vector<int>& nums, int target, int start) {
    int N = nums.size(), ans = N;
    for (int i = 0; i < N; ++i) {
      if (nums[i] == target) ans = min(ans, abs(i - start));
    }
    return ans;
  }
};
