class Solution {
public:
  bool check(vector<int>& nums) {
    int N = nums.size(), gap;
    for (gap = 1; gap < N; ++gap) {
      if (nums[gap] < nums[gap - 1]) break;
    }

    auto nums_s = nums;
    sort(nums_s.begin(), nums_s.end());
    for (int i = 0; i < N; ++i) {
      if (nums_s[i] != nums[(i + gap) % N]) return false;
    }
    return true;
  }
};
