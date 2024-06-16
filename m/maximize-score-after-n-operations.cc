class Solution {
  int d[1 << 14], n;
  vector<int> nums;

  int r(int state) {
    if (d[state] != -1) return d[state];
    if (state == 0) return 0;

    int lev = __builtin_popcount(state) / 2, ret = 0;
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
      if ((state & (1 << i)) && (state & (1 << j))) {
        int nstate = state ^ (1 << i) ^ (1 << j);
        ret = max(ret, lev * __gcd(nums[i], nums[j]) + r(nstate));
      }
    }
    return d[state] = ret;
  }

public:
  int maxScore(vector<int>& nums) {
    n = nums.size(); this->nums = nums;
    memset(d, -1, sizeof(d));
    return r((1 << n) - 1);
  }
};
