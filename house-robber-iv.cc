class Solution {
public:
  int minCapability(vector<int>& nums, int k) {
    int l = 1, r = 0, N = nums.size();
    for (int e : nums) r = max(r, e);
    ++r;

    while (l < r) {
      int m = (l + r) / 2;

      int cnt = 0, i = 0;
      while (i < N) {
        if (nums[i] <= m) {
          ++cnt;
          i += 2;
        }
        else i += 1;
      }

      if (cnt >= k) r = m;
      else l = m + 1;
    }

    return l;
  }
};
