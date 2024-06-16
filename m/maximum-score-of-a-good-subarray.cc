class Solution {
public:
  int maximumScore(vector<int>& nums, int k) {
    int l = k, r = k, n = nums.size(), ans = 0;
    for (int v = nums[k]; v >= 1; --v) {
      while (r < n - 1 && nums[r + 1] >= v) ++r;
      while (l > 0 && nums[l - 1] >= v) --l;
      ans = max(ans, (r - l + 1) * v);
    }
    return ans;
  }
};
