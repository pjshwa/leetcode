class Solution {
public:
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
};
