class Solution {
public:
  int countValidSelections(vector<int>& nums) {
    int ans = 0, N = nums.size();
    for (int si = 0; si < N; ++si) for (int d = -1; d <= 1; d += 2) {
      if (nums[si] != 0) continue;
      int curr = si, cd = d; vector<int> nums_c = nums;
      while (0 <= curr && curr < N) {
        if (nums_c[curr] == 0) curr += cd;
        else {
          --nums_c[curr];
          cd *= -1;
          curr += cd;
        }
      }

      int ok = 1;
      for (int v : nums_c) ok &= (v == 0);
      ans += ok;
    }
    return ans;
  }
};
