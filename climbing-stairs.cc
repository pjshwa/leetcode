class Solution {
  int d[46];
public:
  int climbStairs(int n) {
    d[0] = d[1] = 1;
    for (int i = 2; i <= n; i++) d[i] = d[i - 1] + d[i - 2];
    return d[n];
  }
};
