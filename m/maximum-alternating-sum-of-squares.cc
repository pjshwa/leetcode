class Solution {
  long long q(int v) {
    return 1LL * v * v;
  }

public:
  long long maxAlternatingSum(vector<int>& nums) {
    long long ans = 0, N = nums.size(), l = 0, r = N - 1;
    sort(nums.begin(), nums.end(), [](int a, int b) { return abs(a) > abs(b); });
    for (int i = 0; i < N; ++i) {
      if (i & 1) ans -= q(nums[l++]);
      else ans += q(nums[r--]);
    }
    return ans;
  }
};
