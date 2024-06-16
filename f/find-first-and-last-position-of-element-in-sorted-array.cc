class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (binary_search(nums.begin(), nums.end(), target)) {
      int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
      int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
      return {left, right};
    }
    else return {-1, -1};
  }
};
