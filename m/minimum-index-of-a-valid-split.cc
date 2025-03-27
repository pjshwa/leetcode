class Solution {
public:
  int minimumIndex(vector<int>& nums) {
    int maj = -1, cnt = 0;
    for (int e : nums) {
      if (cnt == 0) maj = e, cnt = 1;
      else if (e == maj) ++cnt;
      else --cnt;
    }

    int tot = 0, N = nums.size();
    for (int e : nums) tot += maj == e;

    int lcnt = 0;
    for (int i = 0; i < N; ++i) {
      lcnt += maj == nums[i];
      int l = i + 1, r = N - i - 1, rcnt = tot - lcnt;
      if (lcnt > l / 2 && rcnt > r / 2) return i;
    }
    return -1;
  }
};
