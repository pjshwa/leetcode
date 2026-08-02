#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500;

class Solution {
  int dp[MAXN][MAXN][2];
  vector<int> nums;

  int rec(int l, int r, int p) {
    if (dp[l][r][p] != 0x3f3f3f3f) return dp[l][r][p];

    int mul = (p == 0 ? 1 : -1);
    if (l == r) return dp[l][r][p] = mul * nums[l];

    int lval = mul * nums[l] + rec(l + 1, r, 1 - p);
    int rval = mul * nums[r] + rec(l, r - 1, 1 - p);
    int ret = p == 0 ? max(lval, rval) : min(lval, rval);
    return dp[l][r][p] = ret;
  }

public:
  bool stoneGame(vector<int>& piles) {
    int N = piles.size();
    memset(dp, 0x3f, sizeof(dp));
    this->nums = piles;
    return rec(0, N - 1, 0) >= 0;
  }
};
