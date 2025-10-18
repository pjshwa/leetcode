class Solution {
public:
  int maxDistinctElements(vector<int>& nums, int k) {
    int N = nums.size();
    sort(nums.begin(), nums.end());

    nums[0] -= k;
    for (int i = 1; i < N; ++i) {
      int t = nums[i - 1] + 1;
      if (t < nums[i]) nums[i] = max(t, nums[i] - k);
      else nums[i] = min(nums[i] + k, t);
    }

    return set<int>(nums.begin(), nums.end()).size();
  }
};
