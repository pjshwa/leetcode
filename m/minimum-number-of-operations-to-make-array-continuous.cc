class Solution {
public:
  int minOperations(vector<int>& nums) {
    int N = nums.size(), ans = N;

    // dedup
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (int start : nums) {
      auto lb = lower_bound(nums.begin(), nums.end(), start);
      auto ub = upper_bound(nums.begin(), nums.end(), start + N - 1);
      ans = min(ans, N - (int)(ub - lb));
    }

    return ans;
  }
};
