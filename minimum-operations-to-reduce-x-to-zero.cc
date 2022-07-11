const int INF = 1e9 + 7;

class Solution {
public:
  int minOperations(vector<int>& nums, int x) {
    int n = nums.size();

    int ans = INF, ep = 0, lsum = 0, rsum = accumulate(nums.begin(), nums.end(), 0);
    for (int sp = 0; sp < n; sp++) {
      while (ep < sp) rsum -= nums[ep++];
      while (ep < n && lsum + rsum > x) rsum -= nums[ep++];
      if (lsum + rsum == x) ans = min(ans, n + sp - ep);

      lsum += nums[sp];
    }

    if (ans == INF) return -1;
    return ans;
  }
};
