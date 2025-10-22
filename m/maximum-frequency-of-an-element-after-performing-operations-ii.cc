const int MAXN = 1e5;

class Solution {
public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int N = nums.size();
    sort(nums.begin(), nums.end());

    int ans = 0, cur = 0, l = 0, r = 0;
    for (int i = 0; i < N; ++i) {
      int t = nums[i];
      while (r < N && nums[r] <= t + k) ++cur, ++r;
      while (l < N && nums[l] < t - k) --cur, ++l;

      int equ = upper_bound(nums.begin(), nums.end(), t) -
                lower_bound(nums.begin(), nums.end(), t);
      int need = cur - equ;
      int val = equ + min(need, numOperations);
      ans = max(ans, val);
    }

    r = 0;
    for (int l = 0; l < N; ++l) {
      long long t = nums[l];
      while (r < N && nums[r] <= t + 2 * k) ++r;
      ans = max(ans, min(r - l, numOperations));
    }

    return ans;
  }
};
