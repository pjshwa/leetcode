class Solution {
public:
  int maxSubarrays(vector<int>& nums) {
    int N = nums.size();
    int score = nums[0];
    for (int i = 1; i < N; ++i) score &= nums[i];
    if (score > 0) return 1;

    int ans = 0; score = (1 << 25) - 1;
    for (int i = 0; i < N; ++i) {
      score &= nums[i];
      if (score == 0) {
        ans++;
        score = (1 << 25) - 1;
      }
    }
    return ans;
  }
};
