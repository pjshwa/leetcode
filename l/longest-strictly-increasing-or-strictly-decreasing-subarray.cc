class Solution {
public:
  int longestMonotonicSubarray(vector<int>& nums) {
    int N = nums.size(), ans = 1;
    
    int streak = 1;
    for (int i = 1; i < N; ++i) {
      if (nums[i] > nums[i - 1]) ++streak;
      else streak = 1;
      ans = max(ans, streak);
    }

    streak = 1;
    for (int i = 1; i < N; ++i) {
      if (nums[i] < nums[i - 1]) ++streak;
      else streak = 1;
      ans = max(ans, streak);
    }
    
    return ans;
  }
};
