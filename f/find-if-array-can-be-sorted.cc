class Solution {
public:
  bool canSortArray(vector<int>& nums) {
    auto nums_s = nums;
    sort(nums_s.begin(), nums_s.end());

    int N = nums.size(), last = -1, lasti = 0;
    for (int i = 0; i < N; ++i) {
      int bcnt = __builtin_popcount(nums[i]);
      if (bcnt != last) {
        sort(nums.begin() + lasti, nums.begin() + i);
        last = bcnt; lasti = i;
      }
    }
    sort(nums.begin() + lasti, nums.end());

    for (int i = 0; i < N; ++i) {
      if (nums[i] != nums_s[i]) return false;
    }
    return true;
  }
};
