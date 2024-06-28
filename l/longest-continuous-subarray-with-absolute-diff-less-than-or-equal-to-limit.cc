const int INF = 0x3f3f3f3f;

class Solution {
public:
  int longestSubarray(vector<int>& nums, int limit) {
    int N = nums.size(), r = 0, ans = 0;
    map<int, int> dt; int maxt = 0, mint = INF;
    auto add = [&](int x) {
      dt[x]++;
      maxt = max(maxt, x);
      mint = min(mint, x);
    };
    auto del = [&](int x) {
      if (--dt[x] == 0) dt.erase(x);
      maxt = dt.empty() ? 0 : dt.rbegin()->first;
      mint = dt.empty() ? INF : dt.begin()->first;
    };

    for (int l = 0; l < N; ++l) {
      while (r < N) {
        add(nums[r]);
        if (maxt - mint > limit) {
          del(nums[r]);
          break;
        }
        else ++r;
      }
      ans = max(ans, r - l);
      del(nums[l]);
    }
    return ans;
  }
};
