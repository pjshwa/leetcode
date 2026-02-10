const int MAXN = 1e5;

class Solution {
  int ecnt = 0, ocnt = 0, C[MAXN + 1];

  void inc(int x) {
    if (C[x] == 0) {
      x % 2 == 0 ? ++ecnt : ++ocnt;
    }
    ++C[x];
  }

  void dec(int x) {
    --C[x];
    if (C[x] == 0) {
      x % 2 == 0 ? --ecnt : --ocnt;
    }
  }

public:
  int longestBalanced(vector<int>& nums) {
    memset(C, 0, sizeof(C)); int N = nums.size(), ans = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = i; j < N; ++j) {
        inc(nums[j]);
        if (ecnt == ocnt) ans = max(ans, j - i + 1);
      }
      for (int j = i; j < N; ++j) dec(nums[j]);
    }
    return ans;
  }
};
