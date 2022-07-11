class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int n = nums.size();

    vector<int> ans = {-1, -1};
    if (ub - lb) ans[0] = lb, ans[1] = ub - 1;
    return ans;
  }
};
