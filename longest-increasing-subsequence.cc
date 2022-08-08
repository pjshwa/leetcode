class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> v{nums[0]};

    for (int i = 1; i < n; i++) {
      if (v.back() < nums[i]) v.push_back(nums[i]);
      else {
        auto it = upper_bound(v.begin(), v.end(), nums[i] - 1);
        *it = nums[i];
      }
    }

    return v.size();
  }
};
