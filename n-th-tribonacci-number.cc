class Solution {
  int d[40];
public:
  Solution() {
    d[0] = 0, d[1] = 1, d[2] = 1;
    for (int i = 3; i <= 37; i++) d[i] = d[i - 1] + d[i - 2] + d[i - 3];
  }
  int tribonacci(int n) {
    return d[n];
  }
};
