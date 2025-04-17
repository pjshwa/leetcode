class Solution {
public:
  int countPairs(vector<int>& nums, int k) {
    int ans = 0, N = nums.size();
    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) {
      ans += nums[i] == nums[j] && ((i * j) % k == 0);
    }
    return ans;
  }
};
