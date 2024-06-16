class Solution {
public:
  int minMoves(vector<int>& nums, int limit) {
    int n = nums.size();

    int T = 2 * limit + 1;
    int by_sums[T], by_mins[T], by_maxs[T];
    for (int i = 0; i < T; ++i) {
      by_sums[i] = by_mins[i] = by_maxs[i] = 0;
    }

    for (int i = 0; i < n / 2; ++i) {
      int a = nums[i], b = nums[n - 1 - i];
      ++by_sums[a + b];
      ++by_mins[min(a, b)];
      ++by_maxs[max(a, b)];
    }

    int ans = n, both_fix = 0;
    for (int v = 2; v <= limit; ++v) both_fix += by_mins[v];

    for (int sum = 2; sum < T; ++sum) {
      int t = by_sums[sum];
      int needs_fix = n / 2 - t;

      ans = min(ans, needs_fix + both_fix);

      both_fix -= by_mins[sum];
      if (sum > limit) both_fix += by_maxs[sum - limit];
    }

    return ans;
  }
};
