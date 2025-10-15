class Solution {
  bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int N = nums.size(); vector<int> P(N, 1);
    for (int i = 1; i < N; ++i) {
      if (nums[i] > nums[i - 1]) P[i] = P[i - 1] + 1;
    }
    for (int i = 2 * k - 1; i < N; ++i) {
      if (P[i - k] >= k && P[i] >= k) return true;
    }
    return false;
  }

public:
  int maxIncreasingSubarrays(vector<int>& nums) {
    int l = 1, r = nums.size() / 2 + 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (hasIncreasingSubarrays(nums, m)) l = m + 1;
      else r = m;
    }
    return l - 1;
  }
};
