class Solution {
public:
  int maxSubarrayLength(vector<int>& nums, int k) {
    map<int, int> T; ++T[nums[0]];
    int l = 0, N = nums.size(), ans = 1;
    for (int i = 1; i < N; ++i) {
      int e = nums[i]; ++T[e];
      while (T[e] > k) --T[nums[l++]];
      ans = max(ans, i - l + 1);
    }
    return ans;
  }
};
