class Solution {
public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    long long ans = 0;
    for (int e : nums) {
      auto uit = upper_bound(nums.begin(), nums.end(), upper - e);
      auto lit = lower_bound(nums.begin(), nums.end(), lower - e);
      ans += uit - lit;
      if (e + e >= lower && e + e <= upper) --ans;
    }
    return ans / 2;
  }
};
