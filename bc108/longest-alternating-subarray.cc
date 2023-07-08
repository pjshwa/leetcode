class Solution {
public:
  int alternatingSubarray(vector<int>& nums) {
    int ans = -1, N = nums.size();

    int streak = 0, mstreak = 0;
    for (int i = 1; i < N; i++) {
      if (nums[i] == nums[i - 1] + 1 * (streak % 2 == 0 ? 1 : -1)) streak++;
      else if (nums[i] == nums[i - 1] + 1) streak = 1;
      else streak = 0;
      mstreak = max(mstreak, streak);
    }

    if (mstreak > 0) ans = mstreak + 1;
    return ans;
  }
};
