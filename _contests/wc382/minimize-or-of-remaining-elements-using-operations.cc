const int MAXB = 30;
const int BMASK = (1 << MAXB) - 1;

class Solution {
public:
  int minOrAfterOperations(vector<int>& nums, int k) {
    int N = nums.size();

    auto bars_cnt = [&](int mask) {
      int bars = -1, asum = BMASK;
      for (int i = 0; i < N; ++i) {
        asum &= nums[i];
        if ((asum & mask) == 0) {
          ++bars;
          asum = BMASK;
        }
      }
      return bars;
    };

    int tmask = 0;
    for (int b = MAXB - 1; b >= 0; --b) {
      if (bars_cnt(tmask | (1 << b)) + k >= N - 1) tmask |= 1 << b;
    }

    int ans = 0;
    for (int b = 0; b < MAXB; ++b) {
      if ((tmask >> b) & 1) continue;
      ans |= 1 << b;
    }
    return ans;
  }
};
