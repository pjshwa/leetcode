class Solution {
  int d[35];
public:
  Solution() {
    d[0] = 0, d[1] = 1;
    for (int i = 2; i <= 30; i++) d[i] = d[i - 1] + d[i - 2];
  }
  int fib(int n) {
    return d[n];
  }
};
