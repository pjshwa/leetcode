class Solution {
public:
  int minimumSubarrayLength(vector<int>& nums, int k) {
    if (k == 0) return 1;
    int N = nums.size(), T[30]{}, val;

    auto add_num = [&](int num, int add) {
      for (int b = 0; b < 30; ++b) {
        if (num & (1 << b)) T[b] += add;
      }
      val = 0;
      for (int b = 0; b < 30; ++b) {
        if (T[b] > 0) val |= (1 << b);
      }
    };

    int r = 0, ans = N + 1;
    for (int l = 0; l < N; ++l) {
      while (r < N && val < k) add_num(nums[r++], 1);
      if (val >= k) ans = min(ans, r - l);
      add_num(nums[l], -1);
    }
    if (ans == N + 1) ans = -1;
    return ans;
  }
};
