class Solution {
public:
  long long zeroFilledSubarray(vector<int>& nums) {
    long long ans = 0, streak = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) streak++;
      else {
        ans += streak * (streak + 1) / 2;
        streak = 0;
      }
    }
    ans += streak * (streak + 1) / 2;
    return ans;
  }
};
