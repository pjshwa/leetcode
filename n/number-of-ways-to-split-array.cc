class Solution {
public:
  int waysToSplitArray(vector<int>& nums) {
    long long sum = accumulate(nums.begin(), nums.end(), 0LL), cur = 0;
    int N = nums.size(), ans = 0;
    for (int i = 0; i < N - 1; ++i) {
      cur += nums[i];
      if (cur >= sum - cur) ++ans;
    }
    return ans;
  }
};
