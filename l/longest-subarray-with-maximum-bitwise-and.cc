class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    int maxv = *max_element(nums.begin(), nums.end());
    int streak = 0, ans = 0;
    for (int e : nums) {
      e == maxv ? ++streak : streak = 0;
      ans = max(ans, streak);
    }
    return ans;
  }
};
