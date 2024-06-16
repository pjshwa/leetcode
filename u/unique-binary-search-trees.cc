class Solution {
  long long d[20];
public:
  int numTrees(int n) {
    d[0] = d[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < i; j++) d[i] = (d[i] + d[i - j - 1] * d[j]);
    }
    return d[n];
  }
};
