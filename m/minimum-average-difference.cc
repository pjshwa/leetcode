const int MAX = 1e5, INF = 0x3f3f3f3f;
using ll = long long;

class Solution {
  ll pl[MAX + 10], pr[MAX + 10];

public:
  int minimumAverageDifference(vector<int>& nums) {
    int n = nums.size();
    memset(pl, 0, sizeof(pl));
    memset(pr, 0, sizeof(pr));

    for (int i = 1; i <= n; ++i) pl[i] = pl[i - 1] + nums[i - 1];
    for (int i = n; i >= 1; --i) pr[i] = pr[i + 1] + nums[i - 1];

    int ans = -1, aval = INF;
    for (int i = 1; i <= n; ++i) {
      int lavg = pl[i] / i, ravg = i == n ? 0 : pr[i + 1] / (n - i);
      int cval = abs(lavg - ravg);
      if (cval < aval) {
        aval = cval;
        ans = i - 1;
      }
    }

    return ans;
  }
};
