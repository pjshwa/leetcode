class Solution {
public:
  int largestInteger(vector<int>& nums, int k) {
    int ans = -1, N = nums.size(), C[51]{};
    for (int e : nums) ++C[e];
    if (k == 1) {
      for (int e : nums) if (C[e] == 1) ans = max(ans, e);
    } else if (k < N) {
      int f = nums[0], b = nums.back();
      for (int e : {f, b}) if (C[e] == 1) ans = max(ans, e);
    } else {
      ans = *max_element(nums.begin(), nums.end());
    }
    return ans;
  }
};
