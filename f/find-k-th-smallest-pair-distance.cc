using pii = pair<int, int>;

class Solution {
public:
  int smallestDistancePair(vector<int>& nums, int k) {
    int N = nums.size();
    sort(nums.begin(), nums.end());

    int l = 0, r = nums.back() - nums[0] + 1;
    while (l < r) {
      int m = (l + r) / 2, cnt = 0;
      for (int i = 0; i < N; ++i) {
        int ll = i, rr = N;
        while (ll < rr) {
          int mm = (ll + rr) / 2;
          if (nums[mm] - nums[i] <= m) ll = mm + 1;
          else rr = mm;
        }
        cnt += ll - i - 1;
      }
      if (cnt < k) l = m + 1;
      else r = m;
    }
    return l;
  }
};
