using ll = long long;
const int MAX = 1000, MOD = 1e9 + 7;

class Solution {
  int C[MAX + 1][MAX + 1];

public:
  int numOfWays(vector<int>& nums) {
    C[0][0] = 1;
    for (int i = 1; i <= MAX; ++i) {
      C[i][0] = 1;
      for (int j = 1; j <= i; ++j) {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
      }
    }

    int N = nums.size();
    function<int(int, int, int)> r = [&](int i, int lb, int ub) {
      if (lb >= ub) return 1;

      int v = nums[i];
      ll ret = C[ub - lb][ub - v];

      for (int j = i + 1; j < N; j++) {
        int nv = nums[j];
        if (lb <= nv && nv <= ub && nv > v) {
          ret = (ret * r(j, v + 1, ub)) % MOD;
          break;
        }
      }
      for (int j = i + 1; j < N; j++) {
        int nv = nums[j];
        if (lb <= nv && nv <= ub && nv < v) {
          ret = (ret * r(j, lb, v - 1)) % MOD;
          break;
        }
      }

      return (int)ret;
    };

    return (r(0, 1, N) - 1 + MOD) % MOD;
  }
};
