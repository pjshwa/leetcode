#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1000, MOD = 1e9 + 7;
int C[MAXN + 1][MAXN + 1];

class Solution {
  void init() {
    C[0][0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
      C[i][0] = C[i][i] = 1;
      for (int j = 1; j < i; ++j) {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
      }
    }
  }

  bool in_range(int x, int l, int r) {
    return l <= x && x <= r;
  }

  ll rec(vector<int>& nums, int i, int l, int r) {
    if (l >= r) return 1;
    int x = nums[i], jl = i + 1, ju = i + 1;
    while (jl < nums.size()) {
      if (in_range(nums[jl], l, r) && nums[jl] < x) break;
      ++jl;
    }
    while (ju < nums.size()) {
      if (in_range(nums[ju], l, r) && nums[ju] > x) break;
      ++ju;
    }
    ll ret = C[r - l][r - x];
    if (jl < nums.size()) ret = (ret * rec(nums, jl, l, x - 1)) % MOD;
    if (ju < nums.size()) ret = (ret * rec(nums, ju, x + 1, r)) % MOD;
    return ret;
  }

public:
  int numOfWays(vector<int>& nums) {
    if (C[0][0] != 1) init();
    return (rec(nums, 0, 1, nums.size()) - 1 + MOD) % MOD;
  }
};
