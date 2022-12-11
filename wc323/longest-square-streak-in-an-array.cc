class Solution {
public:
  int longestSquareStreak(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<int> d(1e5 + 1, 0);
    for (int i = 0; i < n; i++) {
      int q = sqrt(nums[i]);
      if (q * q == nums[i]) d[nums[i]] = d[q] + 1;
      else d[nums[i]] = 1;
    }

    int ans = *max_element(d.begin(), d.end());
    if (ans < 2) ans = -1;
    return ans;
  }
};
