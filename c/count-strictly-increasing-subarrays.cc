class Solution {
public:
  long long countSubarrays(vector<int>& nums) {
    long long ans = 0, streak = 1, N = nums.size();
    for (int i = 1; i < N; ++i) {
      if (nums[i] > nums[i - 1]) ++streak;
      else {
        ans += streak * (streak + 1) / 2;
        streak = 1;
      }
    }
    ans += streak * (streak + 1) / 2;
    return ans;
  }
};
