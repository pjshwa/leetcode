class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;

    long long sum = 1, r = 0, ans = 0, N = nums.size();
    for (int l = 0; l < N; ++l) {
      while (r < N && sum * nums[r] < k) {
        sum *= nums[r];
        ++r;
      }
      ans += r - l;

      if (l == r) ++r;
      else sum /= nums[l];
    }

    return ans;
  }
};
